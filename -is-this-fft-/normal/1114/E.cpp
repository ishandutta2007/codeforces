#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <chrono>
#include <random>

using namespace std;

int val_of (int idx) {
  cout << "? " << idx << endl;

  int ans;
  cin >> ans;

  if (ans == -1) {
    exit(0);
  }

  return ans;
}

bool exists_greater (int val) {
  if (val >= 1000000000) {
    return false;
  }
  cout << "> " << val << endl;

  int ans;
  cin >> ans;

  if (ans == -1) {
    exit(0);
  }

  return ans;
}

int diff (int a, int b) {
  return abs(a - b);
}

int gcd (int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

const int RANDS = 30;

int main () {
  ios::sync_with_stdio(false);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int length;
  cin >> length;
  
  int biggest = 0;
  for (int k = 1 << 29; k != 0; k /= 2) {
    int cur = biggest + k;
    if (exists_greater(cur)) {
      biggest += k;
    }
  }
  biggest++;

  vector<int> knowns (1, biggest);
  for (int i = 0; i < RANDS; i++) {
    knowns.push_back(val_of(1 + rng() % length));
  }

  int d = 0;
  for (int i = 0; i < RANDS + 1; i++) {
    for (int j = i + 1; j < RANDS + 1; j++) {
      d = gcd(d, diff(knowns[i], knowns[j]));
    }
  }

  cout << "! " << biggest - (length - 1) * d << " " << d << endl;
}