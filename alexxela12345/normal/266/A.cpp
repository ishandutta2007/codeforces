#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      ans++;
  }
  cout << ans << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}