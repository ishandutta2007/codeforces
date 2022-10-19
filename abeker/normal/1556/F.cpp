#include <bits/stdc++.h>
using namespace std;

const int MAXN = 14;
const int MOD = 1e9 + 7;

int N;
int a[MAXN];
int prob[MAXN][1 << MAXN];
int dp[1 << MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

int get_trans(int submask, int mask) {
  int res = dp[submask];
  for (int i = 0; i < N; i++)
    if (submask >> i & 1)
      res = mul(res, prob[i][mask ^ submask]);
  return res;
}

int solve() {
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < 1 << N; j++) {
      prob[i][j] = 1;
      for (int k = 0; k < N; k++)
        if (j >> k & 1)
          prob[i][j] = mul(prob[i][j], mul(a[i], pot(a[i] + a[k], MOD - 2)));
    }
  for (int i = 1; i < 1 << N; i++) {
    dp[i] = 1;
    for (int j = (i - 1) & i; j; j = (j - 1) & i) 
      dp[i] = add(dp[i], -get_trans(j, i));
  }
  int sol = 0;
  for (int i = 1; i < 1 << N; i++)
    sol = add(sol, mul(__builtin_popcount(i), get_trans(i, (1 << N) - 1)));
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}