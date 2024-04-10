#include <iostream>

using namespace std;

int maxpw [5] = {500, 1000, 1500, 2000, 2500};
int subtime [5];
int failc [5];
int score [5];

int main () {
  for (int i = 0; i < 5; i++) {
    cin >> subtime[i];
  }
  for (int i = 0; i < 5; i++) {
    cin >> failc[i];
  }

  for (int i = 0; i < 5; i++) {
    score[i] = max(3*(maxpw[i]/10),
		   maxpw[i] - subtime[i]*maxpw[i]/250 - 50*failc[i]);
  }

  int haxc, unhaxc, finscore = 0;
  cin >> haxc >> unhaxc;
  for (int i = 0; i < 5; i++) {
    finscore += score[i];
  }
  
  finscore += haxc*100;
  finscore -= unhaxc*50;
  
  cout << finscore << endl;
}