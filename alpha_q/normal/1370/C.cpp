#include <bits/stdc++.h>

using namespace std;

int t, n;

void one() {
  puts("Ashishgup");
}

void two() {
  puts("FastestFinger");
}

bool isPrime (int x) {
  for (int i = 2; i * i <= x; ++i) if (x % i == 0) return 0;
  return 1;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1) {
      two();
      continue;
    }
    if (n == 2) {
      one();
      continue;
    }
    if (n & 1) {
      one();
      continue;
    }
    int pwr = 0;
    while (~n & 1) n >>= 1, ++pwr;
    if (n == 1) {
      two();
      continue;
    }
    if (pwr > 1) {
      one();
      continue;
    }
    if (isPrime(n)) {
      two();
      continue;
    }
    one();
  }
  return 0;
}