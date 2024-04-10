#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
      char c = s[i];
      char d = t[n-1-i];
      if (c > d) swap(c, d);
      string p = {c, d};
      cnt[p]++;
    }
    bool ok = 1;
    int odds = 0;
    for (auto& [p, c]: cnt) {
      if (c&1) {
        if (p[0] != p[1]) ok = 0;
        odds++;
      }
    }
    if (odds > 1) ok = 0;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}