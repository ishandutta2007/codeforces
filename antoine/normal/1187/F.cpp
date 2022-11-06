#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;
const int mod = (int) 1e9 + 7;

ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

ll modInv(const ll x) {
	return modPow(x, mod - 2);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> l(n + 1, 0), r(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> l[i];
	for (int i = 1; i <= n; ++i)
		cin >> r[i];

	const auto sz = [&](const int i) {
		assert(l[i] <= r[i]);
		return r[i] - l[i] + 1LL;
	};

	ll ans = 0;
	vector<ll> dp(n);
	for (int i = 0; i < n; ++i) {
		const ll c = max(0, min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1);
		dp[i] = 1 - c * modInv(sz(i)) % mod * modInv(sz(i + 1)) % mod;
		(ans += dp[i]) %= mod;
	}

	for (int i = 0; i + 1 < n; ++i) {
		const int L = max(l[i], max(l[i + 1], l[i + 2]));
		const int R = min(r[i], min(r[i + 1], r[i + 2]));
		const ll c = max(0, R - L + 1);
		const ll temp = 1 - (1 - dp[i]) - (1 - dp[i + 1]) + c * modInv(sz(i) * sz(i + 1) % mod * sz(i + 2) % mod);
		(ans += 2 * temp) %= mod;
	}

	ll sum = 0;
	for (int i = 2; i < n; ++i) {
		(sum += dp[i - 2]) %= mod;
		(ans += 2 * dp[i] * sum) %= mod;
	}

	cout << (ans % mod + mod) % mod;
	return 0;
}