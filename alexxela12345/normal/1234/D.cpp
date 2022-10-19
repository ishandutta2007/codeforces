#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  map<char, set<int>> m;
  for (int i = 0; i < n; i++) {
    m[s[i]].insert(i);
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      pos--;
      m[s[pos]].erase(pos);
      s[pos] = c;
      m[s[pos]].insert(pos);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      int ans = 0;
      for (auto &el : m) {
        auto it = el.second.lower_bound(l);
        if (it != el.second.end() && *el.second.lower_bound(l) <= r) {
          ans++;
        }
      }
      cout << ans << endl;
    }
  }
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}