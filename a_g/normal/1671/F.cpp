#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1671/submission/154609861
const int MOD = 998244353;
const int N = 35;
const int M = 15;
const int K = 12;
int dp[N][K][K][K], f[K][K][N], inv[N];
// dp[i][j][k][l] = number of permutations of 0 to i-1 such that
// - the first number in the permutation is j
// - there are k inversions
// - there are l descending steps

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  dp[0][0][0][0] = 1;
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }
  for (int i = 0; i+1 < N; i++) {
    for (int j = 0; j < min(K, i+1); j++) {
      for (int k = 0; k < K; k++) {
        for (int l = 0; l < K; l++) {
          if (dp[i][j][k][l]) {
            for (int p = 0; p <= i && k+p < K && l+(p>j) < K; p++) {
              add(dp[i+1][p][k+p][l+(p>j)], dp[i][j][k][l]);
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      for (int k = 0; k < K; k++) {
        for (int l = 0; l < K; l++) {
          add(f[k][l][i], dp[i][j][k][l]);
        }
      }
    }
  }

  int T;
  cin >> T;
  while (T--) {
    int n, k, x;
    cin >> n >> k >> x;
    if (n < N) {
      cout << f[k][x][n] << '\n';
      continue;
    }
    // for large n, polynomial interpolate starting from 15 (the small cases are
    // exceptions or something)
    int ans = 0;
    for (int i = M; i < N; i++) {
      int term = f[k][x][i];
      for (int j = M; j < N; j++) {
        if (j == i) continue;
        term = 1LL*(n-j)*term % MOD;
        term = 1LL*(i > j ? inv[i-j] : MOD-inv[j-i])*term % MOD;
      }
      add(ans, term);
    }
    cout << ans << '\n';
  }
}