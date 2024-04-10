#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1701/submission/163271615

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> lcp(n+1, vector<int>(m+1));
    for (int i = n-1; i >= 0; i--) {
      for (int j = m-1; j >= 0; j--) {
        if (s[i] == t[j]) {
          lcp[i][j] = lcp[i+1][j+1]+1;
        }
      }
    }
    int ans = n-lcp[0][0]; // case where we remove from suffix only
    int p = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[p]) p++;
      for (int j = 0; j <= p; j++) {
        // delete the first i+1 characters, except for j to match the prefix
        // on prefix: 1+2*(i+1)-j operations
        // on suffix: n-(i+1)-lcp[i+1][j] operations
        // impossible cases give higher numbers? (not sure why)
        ans = min(ans, n-lcp[i+1][j]+i-j+2);
      }
    }

    if (p < m) ans = -1;
    cout << ans << '\n';
  }
}