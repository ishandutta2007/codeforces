#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			(res *= n) %= mod;
		(n *= n) %= mod;
	}
	return res;
}

struct _T {
	ll v;
	_T() {
		v = modPow(2, mod - 2);
	}
} modInv2;

ll M2(ll x) {
	return x * (x + 1) % mod * modInv2.v % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m, U;
	cin >> n >> m >> U;

	vector<ll> b(m + 1, 0);
	for(int i = 1; i <= m; ++i)
		cin >> b[i];

	ll res = modPow(U, n - 2*b[m]);
	for (int i = 1; i <= m; ++i) {
		res *= M2(modPow(U, b[i] - b[i - 1]));
		res %= mod;
	}

	cout << res << '\n';

	return 0;
}