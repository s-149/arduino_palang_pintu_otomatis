// dev by: S-149

#include <Servo.h>  // Mengimpor library Servo untuk mengontrol motor servo
Servo servo;        // Mendeklarasikan objek servo
int angle = 10;     // variabel untuk menyimpan sudut awal motor servo

// mendefinisikan nomor pin
const int trigPin = 12;  // pin trigger sensor ultrasonik
const int echoPin = 11;  // pin echo sensor ultrasonik

// mendefinisikan variabel-variabel untuk menghitung durasi dan jarak
long duration;  // variabel untuk menyimpan durasi dari pulsa ultrasonik yang dikirim
int distance;   // variabel untuk menyimpan jarak yang dihitung dari durasi pulsa

void setup() {
  servo.attach(8);           // Menghubungkan servo ke pin 8 Arduino
  servo.write(angle);        // Mengatur posisi awal servo
  pinMode(trigPin, OUTPUT);  // Mengatur trigPin sebagai Output
  pinMode(echoPin, INPUT);   // Mengatur echoPin sebagai Input
  Serial.begin(9600);        // Memulai komunikasi serial dengan kecepatan 9600 baud
}

void loop() {
  digitalWrite(trigPin, LOW);  // Menghentikan sinyal ultrasonik
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Mengirimkan sinyal ultrasonik
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  // Menghentikan sinyal ultrasonik

  duration = pulseIn(echoPin, HIGH);  // Membaca durasi pulsa ultrasonik yang kembali
  distance = duration * 0.034 / 2;    // Menghitung jarak berdasarkan durasi pulsa

  Serial.print("Distance: ");  // Mencetak label "Distance: " ke Serial Monitor
  Serial.println(distance);    // Mencetak nilai jarak ke Serial Monitor
  delay(100);                 // Delay singkat

  // Mengatur sudut servo berdasarkan jarak yang diukur
  if (distance < 5) {
    servo.write(70);  // Menggerakkan servo ke sudut 180 jika jarak kurang dari 20
    delay(5000); // delay selama 5 detik        
  } else {
    servo.write(180);  // Menggerakkan servo ke sudut 70 jika jarak tidak kurang dari 20
  }
}
