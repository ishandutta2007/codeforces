#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;
const int INF = 1e9;

int N;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN][MAXN * MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d%d", a + i, b + i);
}

void solve() {
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= N; j++)
      for (int k = 0; k <= 100 * N; k++)
        dp[i][j][k] = -INF;
  dp[0][0][0] = 0;
  for (int i = 1; i <= N; i++) 
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= 100 * j; k++) {
        dp[i][j][k] = dp[i - 1][j][k];
        if (j && k >= a[i])
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - a[i]] + b[i]);
      }
  int sum = accumulate(b + 1, b + N + 1, 0);
  for (int i = 1; i <= N; i++) {
    double ans = 0;
    for (int k = 0; k <= 100 * i; k++) 
      ans = max(ans, min((double)(dp[N][i][k] + sum) / 2, (double)k));
    printf("%.10lf ", ans);
  }
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}