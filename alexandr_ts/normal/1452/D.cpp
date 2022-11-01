#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll f[N], f1[N];

ll powMod(ll x, ll pw) {
    if (pw == 0) return 1;
    ll tmp = powMod(x, pw / 2);
    if (pw % 2)
        return (x * tmp) % MOD * tmp % MOD;
    return tmp * tmp % MOD;
}

ll cnk(ll n, ll k) {
    return (f[n] * f1[k] % MOD) * f1[n - k] % MOD;
}

void precalc() {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < N; ++i) {
        f[i] = (f[i - 1] * i) % MOD;
    }
    for (int i = 0; i < N; ++i) {
        f1[i] = powMod(f[i], MOD - 2);
    }
}

ll dp[N];

void solve() {
  int n;
  cin >> n;
  dp[0] = 0;
  dp[1] = powMod(2, MOD - 2);
  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 2] * powMod(4, MOD - 2) + dp[i - 1] * powMod(2, MOD - 2);
    dp[i] %= MOD;
  }
  cout << dp[n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  precalc();
	int t = 1;
	while (t--) {
		solve();
	}
}