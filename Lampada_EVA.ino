// Lampada costruita per Eva in data 24 Dicembre 2021

const int ledR = 3;
const int ledG = 5;
const int ledB = 6;
const int tempPin = A0;
const int intensPin = A1;
const int button = 2;
int bCount;

void setup(){
  pinMode(tempPin, INPUT);
  pinMode(intensPin, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(button, INPUT);
}

void loop(){
  int i;
  int bState = digitalRead(button);
  int intens = analogRead(intensPin) / 4;// Arriva al massimo intorno a 1000, divido per 4 per mantenermi entro i 250
  int trans = analogRead(tempPin) / 5; // Divido per 5 per mantenermi entro i 200
  if(intens == 0){ // Se l'intensità è zero
    spegni(); // Spegni. Blocco reso necessario dal fatto che, mettendo semplicemente intens a zero e accendendo i led in accordo con ciò, rimane un minimo di luce
  }
  if(bState == HIGH){ // Se sto premendo il bottone
    bCount++; // Incrementa lo stato
  }
  if(bCount == 1){ // Colore rosso
      rgb(intens, 0, 0); 
   }else if(bCount == 2){ // Colore verde
      rgb(0, intens, 0);
   }else if(bCount == 3){ // Colore blu
      rgb(0, 0, intens);
   }else if(bCount == 4){ // Arcobaleno
     for(i = 0; i<intens; i++){ // Ciclo R-G
       rgb(intens-i, i, 0);
       delay(trans);
     }
     for(i = 0; i<intens; i++){ // Ciclo G-B
       rgb(0, intens-i, i);
       delay(trans);
     }
     for(i = 0; i<intens; i++){ // Ciclo B-R
       rgb(i , 0, intens-i);
       delay(trans);
     }
   }else{ // Riporto il contatore a 1
      bCount = 1;
   }
  delay(155); // Ritardo per "pulire" la pressione del bottone
}

void rgb(int intR, int intG, int intB){
  analogWrite(ledR, intR);
  analogWrite(ledG, intG);
  analogWrite(ledB, intB);
}

void spegni(){
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
}
