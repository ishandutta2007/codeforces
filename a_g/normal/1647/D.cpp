#include <bits/stdc++.h>
using namespace std;

int spf(int x) {
  for (int i = 2; i*i <= x; i++) {
    if (x % i == 0) return i;
  }
  return x;
}

bool is_pow(int d, int base) {
  while (d % base == 0) {
    d /= base;
  }
  return d == 1;
}

bool good(int x, int d) {
  if (x % (1LL * d * d) != 0) return 0;
  int q = spf(d);
  int r = x/(d*d);
  int s = spf(r);
  if (r == 1 || r == s) return 0;
  if (!is_pow(d, q)) return 1;
  if (d == q) {
    while (r % q == 0) r /= q;
    return r != 1 && r != spf(r);
  }
  if (d == 1LL * q * q && r == 1LL * q * q * q) return 0;
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, d;
    cin >> x >> d;
    cout << (good(x, d) ? "YES" : "NO") << '\n';
  }
}