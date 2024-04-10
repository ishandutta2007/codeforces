#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

vector <ll> pr;
ll q, d, fac[6969], inv[6969];

ll get (ll x) {
  ll sum = 0;
  vector <ll> pwr;
  for (ll p : pr) {
    ll yo = 0;
    while (x % p == 0) x /= p, ++yo;
    pwr.emplace_back(yo), sum += yo;
  }
  ll ret = fac[sum];
  for (ll it : pwr) ret = ret * inv[it] % MOD;
  return ret;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < 6969; ++i) {
    fac[i] = i * fac[i - 1] % MOD;
    inv[i] = bigMod(fac[i], -1);
  }
  cin >> d >> q;
  for (ll i = 2; i * i <= d; ++i) {
    if (d % i) continue;
    pr.emplace_back(i);
    while (d % i == 0) d /= i;
  }
  if (d > 1) pr.emplace_back(d);
  while (q--) {
    ll u, v;
    scanf("%lld %lld", &u, &v);
    ll g = __gcd(u, v);
    ll ans = get(u / g) * get(v / g) % MOD;
    printf("%lld\n", ans);
  }
  return 0;
}