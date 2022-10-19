#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e6 + 5;
const int MOD = 998244353;

int N, M;
int fact[MAXN], ifact[MAXN];
int inv[MAXN];

void load() {
  scanf("%d%d", &N, &M);  
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

inline int divide(int x, int y) {
  return mul(x, inv[y]);
}

int solve() {
  fact[1] = ifact[1] = inv[1] = 1;
  for (int i = 2; i <= N + M + 1; i++) {
    inv[i] = mul(MOD - MOD / i, inv[MOD % i]);
    fact[i] = mul(fact[i - 1], i);
    ifact[i] = mul(ifact[i - 1], inv[i]);
  }
  
  int dp = 0, sum = 0;
  int ex = divide(N + M + 1, M + 1);
  for (int i = 1; i <= N; i++) {
    dp = divide(add(mul(mul(fact[i + M], ifact[i]), ex), mul(M, sum)), i);
    sum = add(sum, dp);
  }
  
  return mul(dp, mul(fact[N], ifact[N + M - 1]));
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}