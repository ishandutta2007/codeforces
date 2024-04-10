#include <bits/stdc++.h>

using namespace std;

int tests;
string s, t;

int main() {
  cin >> tests;
  while (tests--) {
    cin >> s >> t;
    if (t.size() > s.size()) swap(s, t);
    int n = s.size(), m = t.size(), k = n * m / __gcd(n, m);
    string ans = "";
    while (ans.size() < k) ans += t;
    bool ok = 1;
    for (int i = 0; i < ans.size(); i += s.size()) {
      if (ans.substr(i, s.size()) != s) {
        ok = 0;
        break;
      }
    }
    if (ok) cout << ans << '\n';
    else cout << "-1\n";
  }
  return 0;
}