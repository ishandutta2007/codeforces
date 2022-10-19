#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

void solve() {
  int n, k;
  cin >> n >> k;
  int x = 1;
  for (int i = 0; i < k; i++) {
    x *= 10;
  }
  cout << n / gcd(n, x) * x << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}