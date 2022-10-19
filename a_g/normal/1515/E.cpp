#include <bits/stdc++.h>
using namespace std;

const int N = 405;
int fact[N], invfact[N], p2[N];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

int binommod(int n, int k, int MOD) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, MOD;
  cin >> n >> MOD;
  p2[0] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = 2LL * p2[i-1] % MOD;
  }
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  int ans = 0;
  for (int k = 1; 2*(k-1) < n; k++) {
    // k segments
    // sum over a_1+...+a_k=n-k+1 of 2^(n-2*k+1)(n-k+1)! prod(1)/(a_i!)
    int term = 0;
    for (int l = 0; l <= k; l++) {
      term += (l&1 ? -1LL : 1LL) * expmod(k-l, n-k+1, MOD) * binommod(k, l, MOD) % MOD;
      term %= MOD;
    }
    ans = (ans + 1LL * term * p2[n-2*k+1]) % MOD;
  }
  cout << (ans+MOD)%MOD << '\n';
}