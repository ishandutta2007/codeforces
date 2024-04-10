#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1e6+5;
int fact[N], invfact[N];

int inversemod(int p, int q) {
  // assumes p > 0
  // https://codeforces.com/blog/entry/23365
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
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
  int n;
  cin >> n;
  int k = 1LL*n*fact[n] % MOD;
  int ans = 1LL*k*(k+1)/2 % MOD;
  for (int i = 0; i < n; i++) {
    int c = (1LL*fact[n]*invfact[n-i+1] % MOD) * (1LL*(n-i)*(n-i) % MOD+1) % MOD;
    if (i == 0) c = n;
    ans = (ans-1LL*fact[n]*(n+i)+1LL*c*n) % MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
}