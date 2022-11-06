#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

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

const int MaxFact = (int) 1e5 + 9;

ll fact[MaxFact + 9];
ll factInv[MaxFact + 9];

ll C(const int n, const int k) {
	return fact[n] * factInv[k] % mod * factInv[n - k] % mod;
}

ll f(const int n, const int k) {
	if (n < 0)
		return 0;
	return C(n + k - 1, k - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fact[0] = factInv[0] = 1;
	for (int i = 1; i <= MaxFact; ++i) {
		fact[i] = fact[i - 1] * i % mod;
		factInv[i] = modInv(fact[i]);
	}

	int p, s, r;
	cin >> p >> s >> r;

	ll A = 0;
	for (int i = 1; i <= p; ++i) {
		A += (i & 1 ? 1LL : -1LL) * C(p, i) % mod * f(s - r * i, p) % mod;
	}
	A %= mod;

	const ll B = f(s - r, p);
	const ll ans = modInv(p) * A % mod * modInv(B) % mod;
	cerr << A << ' ' << B << endl;
	cout << (ans % mod + mod) % mod;
	return 0;
}