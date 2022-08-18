#include <iostream>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 505;
const int MAX_K = 11;

const int dx [4] = {1, 0, -1, 0};
const int dy [4] = {0, 1, 0, -1};

int cost [MAX_N][MAX_N][4];
int dp [MAX_K][MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m, K;
  cin >> n >> m >> K;

  if (K % 2 != 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
	cout << -1 << " ";
      }
      cout << '\n';
    }
    return 0;
  }
  K /= 2;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m - 1; j++) {
      int x;
      cin >> x;

      cost[i][j][1] = x;
      cost[i][j + 1][3] = x;
    }

    cost[i][1][3] = INF;
    cost[i][m][1] = INF;
  }

  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;

      cost[i][j][0] = x;
      cost[i + 1][j][2] = x;
    }
  }

  for (int j = 1; j <= m; j++) {
    cost[1][j][2] = INF;
    cost[n][j][0] = INF;
  }

  for (int k = 1; k <= K; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
	dp[k][i][j] = INF;
	for (int d = 0; d < 4; d++) {
	  dp[k][i][j] = min(dp[k][i][j], cost[i][j][d] + dp[k - 1][i + dx[d]][j + dy[d]]); 
	}
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << (dp[K][i][j] >= INF ? -1 : 2 * dp[K][i][j]) << " ";
    }
    cout << '\n';
  }
}