#include<bits/stdc++.h>

using lint = long long;

const int MOD = 998244353;

int fac[int(1.1e6)];

int main() {
  fac[0] = 1;
  for(int i = 1; i <= int(1e6); i++) {
    fac[i] = fac[i-1] * (lint)i % MOD;
  }
  int N; scanf("%d", &N);
  lint ans = fac[N], m = N;
  for(int i = 1; i < N; i++) {
    (ans += m * (fac[N-i] - 1) % MOD) %= MOD;
    (m *= (N-i)) %= MOD;
  }
  printf("%lld\n", ans);
  return 0;
}