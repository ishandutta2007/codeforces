#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

const int MxN = 2009;
ll C[MxN + 9][MxN + 9];
vector<ll> pPow[MxN + 9];
ll pPowIntegral[MxN + 9];
ll mdInv[3 * MxN + 9];

inline vector<ll> polMult(const vector<ll> p1, const vector<ll> p2) {
	vector<ll> res(p1.size() + p2.size() - 1, 0);
	for (size_t i = 0; i < p1.size(); ++i)
		for (size_t j = 0; j < p2.size(); ++j)
			(res[i + j] += p1[i] * p2[j]) %= mod;
	return res;
}

ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

inline ll integral(vector<ll> p) {
	ll res = 0;
	for (int i = 0; i < (int) p.size(); ++i)
		(res += p[i] * mdInv[i + 1]) %= mod;
	return res;
}

inline ll pm1(ll x) {
	return x & 1 ? -1 : 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, K, L;
	cin >> n >> K >> L;

	for (int i = 1; i <= 3 * n + 9; ++i)
		mdInv[i] = modPow(i, mod - 2);

	for (int i = 0; i <= n; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}

	pPow[0] = {1};
	for (int i = 1; i <= n; ++i) {
		static const vector<ll> p = { 0, 2, -2 };
		pPow[i] = polMult(pPow[i - 1], p);
		assert(i != 1 || pPow[1] == p);
	}

	cerr << "Test" << endl;

	for (int i = 0; i <= n; ++i)
		pPowIntegral[i] = integral(pPow[i]);

	cerr << "Test" << endl;

	ll ans = 0;
	for (int k = K; k <= n; ++k) {
		ll temp = 0;
		for (int i = 0; i <= n - k; ++i)
			temp += C[n - k][i] * pPowIntegral[k + i] * pm1(n - k - i) % mod;
		(ans += temp % mod * C[n][k] * pm1(n - k)) %= mod;
	}

	cout << (ans % mod * L % mod + mod) % mod;
	return 0;
}