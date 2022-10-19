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
  int n, m;
  cin >> n >> m;
  int a = 1;
  int b = n;
  for (int i = 0; i < m; i++) {
    int aa, bb;
    cin >> aa >> bb;
    if (bb < aa)
      swap(bb, aa);
    a = max(a, aa);
    b = min(b, bb);
  }
  cout << max(0LL, b - a) << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}