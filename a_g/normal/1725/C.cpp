#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 3e5+2;;
int fact[N];
int invfact[N];

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

int inversemod(int p, int q) {
  // assumes p > 0
  // https://codeforces.com/blog/entry/23365
  return (p > 1 ? q-1LL*inversemod(q%p, p)*q/p : 1);
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

  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  for (int& x: d) cin >> x;
  vector<long long> dsum(n+1);
  for (int i = 0; i < n; i++) {
    dsum[i+1] = dsum[i] + d[i];
  }
  int diameters = 0;
  for (int i = 0; i < n; i++) {
    if (2*dsum[i] >= dsum[n]) break;
    if (dsum[n]&1) break;
    diameters += binary_search(dsum.begin(), dsum.end(), dsum[i]+dsum[n]/2);
  }

  int ans = 0;
  for (int k = 0; k <= diameters; k++) {
    int term = binommod(diameters, k);
    term = 1LL*term*fact[m] % MOD;
    term = 1LL*term*invfact[m-k] % MOD;
    term = 1LL*term*expmod(1LL*(m-k)*(m-k-1), diameters-k, MOD) % MOD;
    term = 1LL*term*expmod(m-k, n-2*diameters, MOD) % MOD;
    ans = (ans+term)%MOD;
  }
  cout << ans << '\n';
}