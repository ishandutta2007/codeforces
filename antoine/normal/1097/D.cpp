#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = (int) 1e9 + 7;
const int MaxI = 9000;
ll inv[MaxI + 9];

ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

vector<pair<ll, int>> getFact(ll x) {
	vector<pair<ll, int>> v;
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			v.emplace_back(i, 1);
			for (x /= i; x % i == 0; x /= i)
				v.back().second++;
		}
	if (x != 1)
		v.emplace_back(x, 1);

	return v;
}

ll f(const ll x, const int p, const int k) {
	vector<ll> dp(p + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= p; ++i)
		dp[i] = (dp[i - 1] * x) % mod;

	for (int rep = 0; rep < k; ++rep) {
		partial_sum(dp.begin(), dp.end(), dp.begin());
		for (int i = 0; i <= p; ++i) {
			dp[i] %= mod;
			dp[i] *= inv[i + 1];
			dp[i] %= mod;
		}
	}
	return dp[p];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	inv[1] = 1;
	for (int i = 2; i <= MaxI; ++i)
		inv[i] = modPow(i, mod - 2);

	ll n;
	int k;
	cin >> n >> k;

	ll ans = 1;
	for (auto p : getFact(n)) {
		ans *= f(p.first, p.second, k);
		ans %= mod;
	}
	cout << (ans % mod + mod) % mod;
	return 0;
}