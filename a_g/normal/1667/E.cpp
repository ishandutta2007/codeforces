#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 2e5+5;
int fact[N], invfact[N], inv[N];
int dp[N];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  int n;
  cin >> n;
  int m = (n+1)/2;
  dp[1] = fact[n-1];
  for (int i = 1; i <= m; i++) {
    dp[i] = (1LL * fact[n-m] * fact[n-i] % MOD) * invfact[n-i-m+1] % MOD;
  }
  int s = 0;
  for (int i = m; i >= 1; i--) {
    dp[i] -= s;
    if (dp[i] < 0) dp[i] += MOD;
    s = (s + 1LL * (dp[i]+s)*inv[i-1]) % MOD;
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " \n"[i==n];
  }
}