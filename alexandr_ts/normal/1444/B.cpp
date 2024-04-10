#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll a[N];

ll f[N], f1[N];

ll powMod(ll x, ll pw) { // power
    if (pw == 0) return 1;
    ll tmp = powMod(x, pw / 2);
    if (pw % 2)
        return (x * tmp) % MOD * tmp % MOD;
    return tmp * tmp % MOD;
}

ll cnk(ll n, ll k) {
    return (f[n] * f1[k] % MOD) * f1[n - k] % MOD;
}

void precalc(int n) {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; ++i)
        f[i] = (f[i - 1] * i) % MOD;
    for (int i = 0; i <= n; ++i)
        f1[i] = powMod(f[i], MOD - 2);
}

void solve() {
  int n;
  cin >> n;
  precalc(2 * n + 2);

  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  sort(a, a + 2 * n);

  ll ans = accumulate(a + n, a + 2 * n, 0ll) - accumulate(a, a + n, 0ll);
  ans %= MOD;
  ans *= cnk(2 * n, n);
  ans %= MOD;
  cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}