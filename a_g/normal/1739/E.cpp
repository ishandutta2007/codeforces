#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int d[N][2], dp[N][2][2];

// dp[i][j][0] = max amount of dirty cells in columns i to n-1
//
// dp[i][j][1] = max amount of dirty cells in columns i to n-1 assuming cell (i,
// 1-j) is disallowed
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 2; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      d[j][i] = row[j] == '1';
    }
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        int &x = dp[i][j][k];
        x = d[i][j]+dp[i+1][j][0];
        if (!k && d[i][1-j]) x = max(x, d[i][j]+d[i][1-j]+dp[i+1][1-j][1]);
      }
    }
  }
  cout << dp[0][0][0] << '\n';
}