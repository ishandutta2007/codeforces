#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll fac[N], bfac[N];

ll pw(ll x, ll t) {
	if (t == 0) return 1;
	if (t % 2) return x * pw(x, t - 1) % MOD;
	ll tmp = pw(x, t / 2);
	return tmp * tmp % MOD;
}

void prec(int n) {
	fac[0] = bfac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		bfac[i] = pw(fac[i], MOD - 2);
	}
}

void solve() {
	ll n, k;
	cin >> n >> k;
	prec(n + 1);

	ll ans = 0;
	for (int d = 1; d <= n; ++d) {
		ll cnt = n / d;
		if (cnt < k) break;
		ll add = fac[cnt - 1] * bfac[k - 1] % MOD * bfac[cnt - k] % MOD;
		ans = (ans + add) % MOD;
	}
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