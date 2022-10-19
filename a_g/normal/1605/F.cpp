#include <bits/stdc++.h>
using namespace std;

const int N = 82;
int p2[N*N], C[N][N], dp[N][N], dp2[N][N];

int MOD;

int add(int x, int y) {
  x += y;
  return (x >= MOD ? x-MOD : x);
}

int sub(int x, int y) {
  x -= y;
  return (x < 0 ? x+MOD : x);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k >> MOD;
  for (int i = 0; i < N; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = add(C[i-1][j-1], C[i-1][j]);
    }
  }
  p2[0] = 1;
  for (int i = 1; i < N*N; i++) {
    p2[i] = 2*p2[i-1] % MOD;
  }

  // dp2[i][j] = number of arrays of i distinct positive numbers with j bits in their OR, modulo choosing which j bits
  for (int a = 0; a <= n; a++) {
    for (int b = 0; b <= k; b++) {
      dp2[a][b] = 1;
      for (int i = 1; i <= a; i++) {
        dp2[a][b] = 1LL*dp2[a][b]*(p2[b]-i) % MOD;
      }
      if (dp2[a][b] < 0) dp2[a][b] += MOD;
      for (int c = 0; c < b; c++) {
        dp2[a][b] = sub(dp2[a][b], 1LL*dp2[a][c]*C[b][c] % MOD);
      }
    }
  }

  for (int a = 0; a <= n; a++) {
    dp[a][0] = 1;
    for (int b = 1; b <= k; b++) {
      dp[a][b] = 1LL*(p2[a]-1)*dp[a][b-1]% MOD;
    }
    for (int b = 0; b <= k; b++) {
      for (int c = 0; c < a; c++) {
        if (a == n && a == (c|1)) continue;
        for (int d = 0; d < b; d++) {
          // in the notation of the editorial, (a, b, c, d) = (i, j, i', j')
          int z = 1;
          for (int u: {dp[c][d], C[a][c], C[b][d], p2[d*(a-c)], dp2[a-c][b-d]}) {
            z = 1LL*z*u % MOD;
          }
          dp[a][b] = sub(dp[a][b], z);
        }
      }
    }
  }
  int ans = 0;
  for (int b = 0; b <= k; b++) {
    ans = add(ans, 1LL*dp[n][b]*C[k][b] % MOD);
  }
  cout << ans << '\n';

}