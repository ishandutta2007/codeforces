#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;
const int MOD = 1e9 + 9;

string s;
ll n, a, b, k, t, q, p, ans;

ll bigMod (ll a, ll e) {
  if (e < 0) e += MOD - 1;
  if (a < 0) a += MOD;
  ll r = 1;
  while (e) {
    if (e & 1) r *= a, r %= MOD;
    a *= a, a %= MOD, e >>= 1;
  }
  return r;
}

int main() {
  cin >> n >> a >> b >> k >> s;
  assert((n + 1) % k == 0);
  q = (n + 1) / k;
  for (int i = 0; i < k; ++i) {
    if (s[i] == '+') t += bigMod(a, n - i) * bigMod(b, i);
    else t -= bigMod(a, n - i) * bigMod(b, i);
    t %= MOD;
  }
  p = bigMod(a, -k) * bigMod(b, k) % MOD;
  if (p == 1) ans = q; 
  else ans = (bigMod(p, q) - 1) * bigMod(p - 1, -1) % MOD;
  ans *= t, ans %= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
  return 0;
}