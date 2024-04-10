#include <iostream>

using namespace std;

const short INF = 1e4 + 5;
const int MAX_N = 5e3 + 5;

short dp [MAX_N][MAX_N][3];

void solve () {
  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k < 3; k++) {
        dp[i][j][k] = INF;
      }
    }
  }

  dp[0][0][0] = 1;
  dp[0][0][1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      // always allow state to move forward
      dp[i][j][1] = min(dp[i][j][1], dp[i][j][0]);
      dp[i][j][2] = min(dp[i][j][2], dp[i][j][1]);

      bool must_delete = j == m || s[i] != t[j];

      // state 0
      if (!must_delete) {
        dp[i + 1][j + 1][0] = min(dp[i + 1][j + 1][0], (short) (dp[i][j][0] + 1));
      }
      dp[i + 1][j][0] = min(dp[i + 1][j][0], (short) (dp[i][j][0] + 2));

      if (!must_delete) {
        dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dp[i][j][1]);
      }

      if (!must_delete) {
        dp[i + 1][j + 1][2] = min(dp[i + 1][j + 1][2], (short) (dp[i][j][2] + 1));
      }
      dp[i + 1][j][2] = min(dp[i + 1][j][2], (short) (dp[i][j][2] + 1));
    }
  }

  int ans = min(dp[n][m][0], min(dp[n][m][1], dp[n][m][2]));
  if (ans >= INF) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}