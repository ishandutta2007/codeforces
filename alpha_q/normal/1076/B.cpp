#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

long long sp (long long n) {
  long long p = -1;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      p = i; break;
    }
  }
  if (p == -1) p = n;
  return p;
}

void brute (long long n) {
  long long ret = 0;
  while (n) ++ret, n -= sp(n);
  cout << ret << '\n';
}

int main() {
  long long n;
  cin >> n;
  // brute(n);
  long long p = sp(n);
  if (p == 2) cout << n / 2 << '\n';
  else cout << 1 + (n - p) / 2 << '\n';
  return 0;
}