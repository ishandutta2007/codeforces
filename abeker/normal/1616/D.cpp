#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;

int N, X;
int a[MAXN];
int dp[MAXN][8];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  scanf("%d", &X);
}

bool bad(int x, int mask) {
  for (int i = 0; i < 2; i++)
    for (int j = i + 1; j < 3; j++) {
      int sum = 0;
      bool ok = true;
      for (int k = i; k <= j; k++)
        if (k < x && mask >> k & 1)
          sum += a[x - k];
        else
          ok = false;
      if (ok && sum < 0)
        return true;
    }
  return false;
}

int solve() {
  for (int i = 1; i < 7; i++)
    dp[0][i] = -MAXN;
  for (int i = 1; i <= N; i++) {
    a[i] -= X;
    for (int j = 0; j < 8; j++) {
      dp[i][j] = -MAXN;
      if (bad(i, j))
        continue;
      for (int k = 0; k < 2; k++)
        dp[i][j] = max(dp[i][j], dp[i - 1][(j >> 1) | (k << 2)] + (j & 1));
    }
  }
  return *max_element(dp[N], dp[N] + 8);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}