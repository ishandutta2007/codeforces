#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x: a) cin >> x;
    vector<int> c, d;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b[i] = x;
      ans += x;
      if (a[i]) c.push_back(x);
      else d.push_back(x);
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    int p = (int)c.size();
    int q = (int)d.size();
    if (p > q) {
      for (int x: d) ans += x;
      for (int i = 0; i < q; i++) {
        ans += c[p-1-i];
      }
      cout << ans << '\n';
    }
    else if (p < q) {
      for (int x: c) ans += x;
      for (int i = 0; i < p; i++) {
        ans += d[q-1-i];
      }
      cout << ans << '\n';
    }
    else {
      for (int x: c) ans += x;
      for (int x: d) ans += x;
      ans -= min(c[0], d[0]);
      cout << ans << '\n';
    }
  }
}