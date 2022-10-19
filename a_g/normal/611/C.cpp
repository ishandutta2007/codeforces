#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int dp[2][N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  for (string& row: grid) cin >> row;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i+1 < h && grid[i][j] == '.' && grid[i+1][j] == '.') {
        dp[0][i+1][j+1] = 1;
      }
      if (j+1 < w && grid[i][j] == '.' && grid[i][j+1] == '.') {
        dp[1][i+1][j+1] = 1;
      }
    }
  }
  for (int z = 0; z < 2; z++) {
    for (int i = 0; i < N; i++) {
      for (int j = 1; j < N; j++) {
        dp[z][i][j] += dp[z][i][j-1];
      }
    }
    for (int i = 1; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[z][i][j] += dp[z][i-1][j];
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << (dp[0][r2-1][c2]-dp[0][r1-1][c2]-dp[0][r2-1][c1-1]+dp[0][r1-1][c1-1])
     +(dp[1][r2][c2-1]-dp[1][r1-1][c2-1]-dp[1][r2][c1-1]+dp[1][r1-1][c1-1]) << '\n';
  }
}