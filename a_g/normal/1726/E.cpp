#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 3e5+2;
int fact[N];
int invfact[N];
int involution[N];

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
  involution[0] = 1;
  involution[1] = 1;
  for (int i = 2; i < N; i++ ){
    involution[i] = (involution[i-1]+1LL*(i-1)*involution[i-2]) % MOD;
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int k = 0; 4*k <= n; k++) {
      // form 2k pairs, then make k 4-cycles
      int term = 1LL*binommod(n-2*k, 2*k) * involution[n-4*k] % MOD;
      term = 1LL*term*fact[2*k] % MOD;
      term = 1LL*term*invfact[k] % MOD;
      ans = (ans+term)%MOD;
    }
    cout << ans << '\n';
  }
}