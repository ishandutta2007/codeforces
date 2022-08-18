#include <iostream>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 5e3 + 5;

int dp [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i < n && j < m && s[i] == t[j]) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
      }

      if (i < n) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
      }

      if (j < m) {
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << '\n';
}