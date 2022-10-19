#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int R, N;
int t[MAXN], x[MAXN], y[MAXN];
int dp[MAXN], suff[MAXN];

void load() {
  scanf("%d%d", &R, &N);
  x[0] = y[0] = 1;
  for (int i = 1; i <= N; i++)
    scanf("%d%d%d", t + i, x + i, y + i);
}

int solve() {
  for (int i = N; i >= 0; i--) {
    int limit = min(N, i + 2 * R);
    dp[i] = suff[limit + 1];
    for (int j = i + 1; j <= limit; j++)
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[j] - t[i] && dp[j] > dp[i]) 
        dp[i] = dp[j];
    suff[i] = max(suff[i + 1], ++dp[i]);
  }
  return dp[0] - 1;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}