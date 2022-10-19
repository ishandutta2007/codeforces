#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  map<char, int> m;
  m['>'] = 8;
  m['<'] = 9;
  m['+'] = 10;
  m['-'] = 11;
  m['.'] = 12;
  m[','] = 13;
  m['['] = 14;
  m[']'] = 15;
  int ans = 0;
  for (char c : s) {
    ans *= 16;
    ans += m[c];
    ans %= 1000003;
  }
  cout << ans << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}