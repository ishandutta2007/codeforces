#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 5;
const int INF = 1e9 + 5;

char grid [MAX_N][MAX_N];
int cost [MAX_N][2];
int dp [MAX_N][MAX_N][2];

int main () {
  ios::sync_with_stdio(false);

  int height, width, x, y;
  cin >> height >> width >> x >> y;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> grid[i][j];

      if (grid[i][j] == '#') {
        cost[j][0]++;
      } else {
        cost[j][1]++;
      }
    }
  }

  dp[0][1][0] = cost[0][0];
  dp[0][1][1] = cost[0][1];
  for (int j = 2; j <= y; j++) {
    for (int k = 0; k < 2; k++) {
      dp[0][j][k] = INF;
    }
  }

  for (int i = 1; i < width; i++) {
    for (int j = 1; j <= y; j++) {
      for (int k = 0; k < 2; k++) {
        if (j == 1) {
          dp[i][j][k] = INF;
          for (int jj = x; jj <= y; jj++) {
            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][jj][!k]);
          }
          dp[i][j][k] += cost[i][k];
        } else {
          dp[i][j][k] = dp[i - 1][j - 1][k] + cost[i][k];
        }
      }
    }
  }

  int ans = INF;
  for (int j = x; j <= y; j++) {
    for (int k = 0; k < 2; k++) {
      ans = min(ans, dp[width - 1][j][k]);
    }
  }
  cout << ans << endl;
}