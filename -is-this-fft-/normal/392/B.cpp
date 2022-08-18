#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 45;

ll cost [3][3];

ll dp [MAX_N][3][3][3];

int main () {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> cost[i][j];
    }
  }

  int n;
  cin >> n;

  for (int m = 1; m <= n; m++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        int k = 3 ^ i ^ j;
        dp[m][i][j][k] = min(cost[i][j]
                             + dp[m - 1][i][k][j]
                             + dp[m - 1][k][j][i]
                             ,
                             cost[i][k] + cost[k][j]
                             + 2 * dp[m - 1][i][j][k]
                             + dp[m - 1][j][i][k]);
      }
    }
  }
  
  cout << dp[n][0][2][1] << '\n';
}