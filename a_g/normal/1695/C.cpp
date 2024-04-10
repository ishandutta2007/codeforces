#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
int dp[N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    if ((n+m)%2 == 0) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = a[i][j];
        if (i == 0 && j == 0) continue;
        else if (i == 0) dp[i][j] += dp[i][j-1];
        else if (j == 0) dp[i][j] += dp[i-1][j];
        else dp[i][j] += max(dp[i][j-1], dp[i-1][j]);
      }
    }
    if (dp[n-1][m-1] < 0) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = a[i][j];
        if (i == 0 && j == 0) continue;
        else if (i == 0) dp[i][j] += dp[i][j-1];
        else if (j == 0) dp[i][j] += dp[i-1][j];
        else dp[i][j] += min(dp[i][j-1], dp[i-1][j]);
      }
    }
    cout << (dp[n-1][m-1] > 0 ? "NO" : "YES") << '\n';
  }
}