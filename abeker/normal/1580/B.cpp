#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;

int N, M, K, P;
int fact[MAXN];
int dp[MAXN][MAXN][MAXN];
int choose[MAXN][MAXN];

void load() {
  scanf("%d%d%d%d", &N, &M, &K, &P);
}

inline int add(int x, int y) {
  x += y;
  if (x >= P)
    return x - P;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % P;
}

inline int get_dp(int n, int m, int k) {
  if (n < m)
    return k ? 0 : fact[n];
  return dp[n][m][k];
}

int solve() {
  fact[0] = 1;
  for (int i = 1; i <= N; i++)
    fact[i] = mul(fact[i - 1], i);
  choose[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; j++)
      choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= N; i++) {
    dp[i][0][0] = dp[i][1][1] = fact[i];
    for (int j = 2; j <= M && j <= i; j++)
      for (int k = 0; k <= K && k <= i; k++)
        for (int p = 1; p <= i; p++)
          for (int l = 0; l <= k; l++) {
            int dp_left = get_dp(p - 1, j - 1, l);
            int dp_right = get_dp(i - p, j - 1, k - l);
            if (dp_left && dp_right)
              dp[i][j][k] = add(dp[i][j][k], mul(choose[i - 1][p - 1], mul(dp_left, dp_right)));
          }
  }
  return get_dp(N, M, K);
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}