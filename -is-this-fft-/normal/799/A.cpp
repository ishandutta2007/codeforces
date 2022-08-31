#include <iostream>

using namespace std;

int sim1 (int need, int mins, int size) {
  int cakec = 0;
  for (int i = 0; true; i++) {
    if (i > 0 && i % mins == 0) {
      cakec += size;
    }

    if (cakec >= need) {
      return i;
    }
  }
}

int sim2 (int need, int mins, int size, int oven) {
  int cakec = 0;
  for (int i = 0; true; i++) {
    if (i > 0 && i % mins == 0) {
      cakec += size;
    }

    if (i > oven && i % mins == oven % mins) {
      cakec += size;
    }
    
    if (cakec >= need) {
      return i;
    }
  }
}

int main () {
  int n, t, k, d;
  cin >> n >> t >> k >> d;

  if (sim1(n, t, k) <= sim2(n, t, k, d)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}