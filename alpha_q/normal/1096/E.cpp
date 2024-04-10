#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 50005;
const int MOD = 998244353;

int p, s, r; ll ans, fac[N], ifac[N];

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

inline ll comb (ll x, ll y) {
  if (x < y or x < 0 or y < 0) return 0;
  return fac[x] * (ifac[y] * ifac[x - y] % MOD) % MOD;
}

inline ll get (ll x, ll y) {
  if (y == 0) return x == 0;
  return comb(x + y - 1, y - 1);
}

// sum of pos variables = sum, each of them < up
ll way (int sum, int pos, int up) {
  ll tot = 0;
  for (int i = 0; i <= pos and i * up <= sum; ++i) {
    ll add = comb(pos, i) * get(sum - i * up, pos) % MOD;
    if (i & 1) {
      tot -= add; if (tot < 0) tot += MOD;
    } else {
      tot += add; if (tot >= MOD) tot -= MOD;
    }
  }
  return tot;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * 1LL * i % MOD;
  ifac[N - 1] = bigMod(fac[N - 1], -1);
  for (int i = N - 1; i; --i) ifac[i - 1] = ifac[i] * 1LL * i % MOD;
  cin >> p >> s >> r;
  for (int k = 1; k <= p; ++k) {
    ll inv = bigMod(k, -1);
    for (int x = r; x * k <= s; ++x) {
      ll add = comb(p - 1, k - 1) * way(s - x * k, p - k, x) % MOD;
      add = add * inv % MOD; 
      ans += add; if (ans >= MOD) ans -= MOD;
    }
  }
  ans = ans * bigMod(get(s - r, p), -1) % MOD;
  cout << ans << '\n';
  return 0;
}

// sum a_i = s - r
// k people get highest x
// for k = 1 to p:
//   for x = r to s:
//     ans += C(p - 1, k - 1) * way(s - x * k, p - k, x - 1) * 1/k