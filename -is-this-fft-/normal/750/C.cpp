#include <iostream>

const int INF = 2023456789;
const int MAX_CONT = 200005;

using namespace std;

int change [MAX_CONT], divis [MAX_CONT];

int main () {
  int contestc;
  cin >> contestc;

  for (int i = 0; i < contestc; i++) {
    cin >> change[i] >> divis[i];
  }

  int minim = -INF, maxim = INF, delta = 0;

  if (divis[0] == 1) {
    minim = 1900;
  } else if (divis[0] == 2) {
    maxim = 1899;
  }

  for (int i = 0; i < contestc; i++) {
    maxim += change[i];
    minim += change[i];

    if (i != contestc - 1) {
      if (divis[i + 1] == 2) {
        maxim = min(maxim, 1899);
      } else {
        minim = max(minim, 1900);
      }
    }
  }

  if (minim > maxim) {
    cout << "Impossible" << endl;
  } else if (maxim >= 1000000000) {
    cout << "Infinity" << endl;
  } else {
    cout << maxim << endl;
  }
}