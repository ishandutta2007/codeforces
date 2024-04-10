#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 505;

int n, mod;
ll fac[N], stirling[N][N];

ll bigMod (ll a, ll e) {
  if (e == -1) e = mod - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % mod;
    a = a * a % mod, e >>= 1;
  }
  return ret;
}

int main() {
  cin >> n >> mod;
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = i * fac[i - 1] % mod;
  stirling[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      stirling[i][j] = (stirling[i - 1][j - 1] + j * stirling[i - 1][j]) % mod;
    }
  }
  ll ans = 0, pwr = 1, inv = 1 + mod >> 1, base = inv * inv % mod;
  for (int k = 1; k <= n; ++k) {
    pwr = pwr * base % mod;
    ll add = fac[k] * stirling[n - k + 1][k] % mod * pwr % mod;
    ans += add, ans %= mod;
  }
  for (int i = 0; i <= n; ++i) ans = ans * 2 % mod;
  cout << ans << '\n';
  return 0;
}