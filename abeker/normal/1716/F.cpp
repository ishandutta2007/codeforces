#include <bits/stdc++.h>
using namespace std;

const int MAXK = 2e3 + 5;
const int MOD = 998244353;

int surj[MAXK][MAXK];

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

void init() {
  surj[0][0] = 1;
  for (int n = 1; n < MAXK; n++)
    for (int k = 1; k <= n; k++)
      surj[n][k] = add(surj[n - 1][k - 1], mul(k, surj[n - 1][k]));
}

int solve() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  int sol = 0, power = 1, falling = 1;
  int p = mul((M + 1) / 2, pot(M, MOD - 2));
  for (int k = 0; k <= K; k++) {
    sol = add(sol, mul(surj[K][k], mul(falling, power)));
    falling = mul(falling, add(N, -k));
    power = mul(power, p);
  }
  return mul(sol, pot(M, N));
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}