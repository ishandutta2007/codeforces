#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = (int) 1e9 + 7;
const ll Mx = (int) 2e6 + 9;

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

ll fact[Mx + 9];
ll factInv[Mx + 9];

ll C(const int n, const int k) {
	return fact[n] * factInv[k] % mod * factInv[n - k] % mod;
}

ll P(const ll n, const ll k) {
	return C(n + k - 1, n);
}

ll Cayley(const ll n, const ll k) {
	if (k == n)
		return 1;
	return k * modPow(n, n - k - 1) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fact[0] = factInv[0] = 1;
	for (int i = 1; i <= Mx; ++i) {
		fact[i] = fact[i - 1] * i % mod;
		factInv[i] = modInv(fact[i]);
	}

	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	for (ll len = 1; len <= min(n - 1, m); ++len) {
		ans += C(n-2, len - 1) * fact[len - 1] % mod * Cayley(n, len + 1) % mod * modPow(m, n - 1 - len) % mod * P(m - len, len) % mod;

		//cerr << C(n-2, len - 1)  << ' ' << fact[len - 1]  << ' ' << Cayley(n, len + 1) << ' ' << modPow(m, n - 1 - len)  << ' ' << P(m - len, len) << endl;
		ans %= mod;
		// cerr << ans << '\n';
	}
	cout << ans;
	return 0;
}