#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int d = 1; d < n; d += 2) {
      for (int l = 0; l+d < n; l++) {
        int r = l+d;
        if (d == 1) {
          dp[l][r] = s[l] != s[r];
          continue;
        }
        if ((s[l] < s[l+1] || dp[l+2][r]) && (s[l] < s[r] || dp[l+1][r-1])) dp[l][r] = 1;
        if ((s[r] < s[r-1] || dp[l][r-2]) && (s[r] < s[l] || dp[l+1][r-1])) dp[l][r] = 1;
      }
    }
    cout << (dp[0][n-1] ? "Alice" : "Draw") << '\n';
  }
}