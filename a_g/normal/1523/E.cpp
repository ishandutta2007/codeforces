#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+5;
int fact[N];
int invfact[N];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
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

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for (int l = 1; l <= n-(k-1)*(l-1); l++) {
      // x_1+...+x_{l-1}+y_1+y_2 = n-l, x_i>= k-1
      int states = binommod(n-(k-1)*(l-1), l);
      int prob = (1LL*fact[l]*fact[n-l] % MOD)*invfact[n] % MOD;
      ans += 1LL*states*prob % MOD;
      if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
  }
}