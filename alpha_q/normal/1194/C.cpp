#include <bits/stdc++.h>

using namespace std;

string s, t, p;
int q, has[30], need[30];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> q;
  while (q--) {
    cin >> s >> t >> p;
    memset(has, 0, sizeof has);
    memset(need, 0, sizeof need);
    int at = 0;
    for (int i = 0; i < t.size(); ++i) {
      if (at < s.size() and s[at] == t[i]) ++at;
      else ++need[t[i] - 'a'];
    }
    if (at < s.size()) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < p.size(); ++i) ++has[p[i] - 'a'];
    int bad = 0;
    for (int i = 0; i < 26; ++i) if (has[i] < need[i]) {
      bad = 1; break;
    }
    cout << (bad ? "NO" : "YES") << '\n';
  }
  return 0;
}