#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 14;
const int N = 5e5 + 10;

ll fac[N], bfac[N];
ll pw2[N];

ll pw(ll x, ll t) {
	if (!t) return 1;
	if (t % 2) return x * pw(x, t - 1) % MOD;
	ll tmp = pw(x, t / 2);
	return tmp * tmp % MOD;
}

void prec(int n) {
	pw2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw2[i] = pw2[i - 1] * 2 % MOD;
	}
	fac[0] = bfac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		bfac[i] = pw(fac[i], MOD - 2);
	}	
}

ll cnk(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * bfac[k] % MOD * bfac[n - k] % MOD;
}

void solve() {
	ll n, m;
	cin >> n >> m;

	prec(max(n, m) + 1);
	n--;
	
	ll ans = 0;
	for (ll x = 1; x <= m; ++x) {
		ans = (ans + cnk(x - 1, n - 1) * pw2[n - 1] % MOD * (n - 1)) % MOD;
	}
	ans = ans * bfac[2] % MOD;
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