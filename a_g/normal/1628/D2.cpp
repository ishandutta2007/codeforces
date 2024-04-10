#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e6+5;
int fact[N];
int invfact[N];

int expmod(long long a, long long b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

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

  int half = inversemod(2, MOD);

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
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 0; i < m; i++) {
      ans += 1LL*(m-i)*binommod(n, i) % MOD;
      ans %= MOD;
    }
    ans = 1LL*ans*expmod(2, MOD-n, MOD) % MOD;
    ans = 1LL*k*ans % MOD;
    cout << ans << '\n';
  }
}