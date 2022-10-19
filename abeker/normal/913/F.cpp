#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const int MOD = 998244353;

int N, P;
int scc[MAXN], ans[MAXN];
int dp[MAXN][MAXN];

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

int divide(int x, int y) {
  return mul(x, pot(y, MOD - 2));
}

void load() {
  int a, b;
  scanf("%d%d%d", &N, &a, &b);
  P = divide(a, b);
}

int solve() {
  for (int n = 0; n <= N; n++) {
    dp[n][0] = 1;
    for (int k = 1; k <= n; k++)
      dp[n][k] = add(mul(dp[n - 1][k], pot(P, k)), mul(dp[n - 1][k - 1], pot(add(1, -P), n - k)));
  }
  for (int n = 1; n <= N; n++) {
    int sum = 0;
    for (int k = 1; k < n; k++) {
      int prob = mul(dp[n][k], scc[k]);
      ans[n] = add(ans[n], mul(prob, add(add(ans[k], ans[n - k]), k * (k - 1) / 2 + k * (n - k))));
      sum = add(sum, prob);
    }
    scc[n] = add(1, -sum);
    ans[n] = divide(add(ans[n], mul(scc[n], n * (n - 1) / 2)), sum);
  }
  return ans[N];
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}