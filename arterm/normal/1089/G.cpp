#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int k;
  cin >> k;
  vector<int> a(7);
  int s = 0;
  for (int i = 0; i < 7; ++i) {
    cin >> a[i];
    s += a[i];
  }
  int res = 1e9;
  for (int it = 0; it < 7; ++it) {
    int c = (k - 1) / s;
    int x = c * s;
    int cur = c * 7;
    int p = 0;
    while (x < k) {
      ++cur;
      x += a[p++];
      p %= 7;
    }
    res = min(res, cur);
    rotate(a.begin(), a.begin() + 1, a.end());
  }
  cout << res << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}