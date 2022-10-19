#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    vector<vector<int>> a(2, vector<int>(m));
    vector<vector<int>> dp(2, vector<int>(m));
    vector<vector<int>> dp2(2, vector<int>(m));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    a[0][0] = -1;
    for (int j = m-1; j >= 0; j--) {
      if (j == m-1) {
        dp2[0][j] = max(a[0][j]+2, a[1][j]+1);
        dp2[1][j] = max(a[1][j]+2, a[0][j]+1);
        dp[0][j] = dp2[0][j];
        dp[1][j] = dp2[1][j];
      }
      else {
        dp2[0][j] = max({a[0][j]+2*(m-j), dp2[0][j+1]+1, a[1][j]+1});
        dp2[1][j] = max({a[1][j]+2*(m-j), dp2[1][j+1]+1, a[0][j]+1});
        dp[0][j] = min(dp2[0][j], max({a[0][j]+2*(m-j), a[1][j]+2*(m-j)-1, dp[1][j+1]}));
        dp[1][j] = min(dp2[1][j], max({a[1][j]+2*(m-j), a[0][j]+2*(m-j)-1, dp[0][j+1]}));
      }
    }
    cout << dp[0][0] << '\n';
  }
}