#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  string s;
  cin >> s;
  if (s[0] >= 'a' && s[0] <= 'z') {
    s[0] += 'A' - 'a';
  }
  cout << s << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}