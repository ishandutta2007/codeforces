#include <bits/stdc++.h>
using namespace std;

const int N = 103;
int dp[N][N][N], C[N][N], fact[N];
int MOD;

int add(int x, int y) {
  x += y;
  return (x >= MOD ? x-MOD : x);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k >> MOD;
  fact[0] = 1;
  C[0][0] = 1;
  for (int i = 1; i < N; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = add(C[i-1][j-1], C[i-1][j]);
    }
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }

  for (int j = 0; j < N; j++) dp[0][j][0] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j > i || j == 0) {
        dp[i][j][0] = fact[i];
        continue;
      }
      for (int k = 0; k <= i; k++) {
        // constant factor optimization?
        if (k > 2 && j+k > i) continue;
        // pick the position of the maximum element
        for (int pos = 1; pos <= (i+1)/2; pos++) {
          // pos-1 elements on the left, n-pos elements on the right
          // x good elements from the left, k-x (or k-1-x good elements) from
          // the right
          //
          // use symmetry to halve the number of positions to iterate over
          for (int x = 0; x <= k; x++) {
            int y = k-(j==1)-x;
            if (x > pos-1 || y > i-pos || y < 0) continue;
            int term = (1LL*dp[pos-1][j-1][x]*dp[i-pos][j-1][y] % MOD)*C[i-1][pos-1] % MOD;
            dp[i][j][k] = add(dp[i][j][k], term);
            if (2*pos != i+1) {
              dp[i][j][k] = add(dp[i][j][k], term);
            }
          }
        }
        //cout << i << " " << j << " " << k << " " << dp[i][j][k] << '\n';
      }
    }
  }
  cout << dp[n][m][k] << '\n';
}