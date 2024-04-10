#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1001000;

ll n, m, a, q, c[N], f[N], row[N];

ll bigMod (ll x, ll y, ll mod) {
  ll r = 1LL;
  while (y) {
    if (y & 1) r = (r * x) % mod;
    x = (x * x) % mod, y >>= 1;
  }
  return r;
} 

ll inv (ll x, ll mod) {
  return bigMod(x, mod - 2, mod);
}

ll comb (ll x, ll y, ll mod) {
  if (x < y) return 0;
  ll r = (inv(f[y], mod) * inv(f[x - y], mod)) % mod;
  return (r * f[x]) % mod;
}

int main() {
  cin >> n >> m >> a >> q;
  ll phi = q, _q = q;
  for (ll i = 2; i * i <= _q; ++i) {
    if (_q % i) continue;
    phi /= i, phi *= (i - 1LL);
    while (_q % i == 0) _q /= i;
  }
  if (_q > 1) phi /= _q, phi *= (_q - 1LL);
  assert(bigMod(a, phi, q) == 1);
  ll order = -1;
  for (ll i = 2; i * i <= phi; ++i) {
    if (phi % i) continue;
    if (bigMod(a, i, q) == 1) {
      order = i;
      break;
    }
    while (phi % i == 0) phi /= i;
  }
  if (order == -1 and phi > 1) {
    assert(bigMod(a, phi, q) == 1);
    order = phi;
  }
  f[0] = 1;
  for (ll i = 1; i < N; ++i) {
    f[i] = (f[i - 1] * i) % order;
  }
  for (int i = 0; i < n; ++i) {
    row[i] = comb(m, i, order);
    if (i) row[i] += row[i - 1], row[i] %= order;
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld ", bigMod(a, row[n - 1 - i], q));
  }
  puts("");
  return 0;
}