const int analogInPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(analogInPin, INPUT);
}

void loop() {
  Serial.println(currentRead());
  delay(500);
}

float currentRead() {
  int temp = 0;
  int maxAmp = 0;

  for (int i = 1; i < 200; i++) { //200 represents on cyle of 20ms of the AC current (50Hz)
    temp = analogRead(A0);
    if (temp > maxAmp) {
      maxAmp = temp;
    }
    delayMicroseconds(100);
  }
  //return (0.02354*maxAmp);
  return (maxAmp);
}
