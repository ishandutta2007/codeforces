#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+5;
int fact[N], invfact[N];

int inversemod(int p, int q) {
  // assumes p > 0
  // https://codeforces.com/blog/entry/23365
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
}

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
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
  int n, k;
  cin >> n >> k;
  k = min(k, n);
  // (n choose 0) + (n choose 1) + ... + (n choose k)
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    ans += binommod(n, i);
    if (ans >= MOD) ans -= MOD;
  }
  cout << ans << '\n';
}