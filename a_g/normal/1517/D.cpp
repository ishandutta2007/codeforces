#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int K = 12;
const int INF = 1e9;
int dp[N][N][K];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  if (k&1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << -1 << " \n"[j+1==m];
      }
    }
    return 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int z = 1; z < K; z++) {
        dp[i][j][z] = INF;
      }
    }
  }

  k /= 2;
  vector<vector<int>> c1(n, vector<int>(m-1));
  vector<vector<int>> c2(n-1, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m-1; j++) {
      cin >> c1[i][j];
    }
  }
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c2[i][j];
    }
  }

  for (int z = 1; z <= k; z++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i > 0) {
          dp[i][j][z] = min(dp[i][j][z], c2[i-1][j]+dp[i-1][j][z-1]);
        }
        if (i < n-1) {
          dp[i][j][z] = min(dp[i][j][z], c2[i][j]+dp[i+1][j][z-1]);
        }
        if (j > 0) {
          dp[i][j][z] = min(dp[i][j][z], c1[i][j-1]+dp[i][j-1][z-1]);
        }
        if (j < m-1) {
          dp[i][j][z] = min(dp[i][j][z], c1[i][j]+dp[i][j+1][z-1]);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << 2*dp[i][j][k] << " \n"[j+1==m];
    }
  }
}