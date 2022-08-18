#include <iostream>

const int MAX_S = 100005;

using namespace std;

int numbers [MAX_S];
int ipos [MAX_S];

int main () {
  int wagonc;

  cin >> wagonc;
  for (int i = 1; i <= wagonc; i++) {
    cin >> numbers[i];
    ipos[numbers[i]] = i;
  }
  
  int bestl = 1, curl = 1;
  
  for (int i = 2; i <= wagonc; i++) {
    if (ipos[i] > ipos[i - 1]) {
      curl++;
      if (curl > bestl) {
	bestl = curl;
      }
    } else {
      curl = 1;
    }
  }

  cout << wagonc - bestl << endl;
}