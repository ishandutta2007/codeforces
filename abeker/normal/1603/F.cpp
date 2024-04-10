#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXK = 1e7 + 5;
const int MOD = 998244353;

int prod[MAXK], inv[MAXK];

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline int mul(int x, int y) {
  return (ll)x * y % MOD;
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
  int curr = 1;
  prod[0] = inv[0] = 1;
  for (int i = 1; i < MAXK; i++) {
    prod[i] = mul(prod[i - 1], curr);
    inv[i] = pot(prod[i], MOD - 2);
    curr = add(mul(curr, 2), 1);
  }
}

int solve() {
  int N, K, X;
  scanf("%d%d%d", &N, &K, &X);
  if (!X)
    return N > K ? 0 : mul(mul(prod[K], inv[K - N]), pot(2, (ll)N * (N - 1) / 2 % (MOD - 1)));
  int pw = pot(2, N), curr = 1, sum = 0;
  for (int i = 0; i < K; i++) {
    int tmp = mul(curr, inv[i]);
    sum = add(sum, (K - i) % 2 ? tmp : -tmp);
    curr = mul(curr, pw);
  }
  return add(curr, -mul(add(pw, -1), mul(sum, prod[K - 1])));
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}