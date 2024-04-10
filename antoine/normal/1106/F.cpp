#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;

vector<vector<ll>> matrixMult(const vector<vector<ll>> A, const vector<vector<ll>> B) {
	assert(!A.empty() && A[0].size() == B.size());
	vector<vector<ll>> C(A.size(), vector<ll>(B[0].size(), 0));
	for (int i = 0; i < (int) C.size(); ++i)
		for (int j = 0; j < (int) C[0].size(); ++j)
			for (int k = 0; k < (int) A[0].size(); ++k)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % (mod - 1);
	return C;
}

vector<vector<ll>> matrixIdentity(const int n) {
	vector<vector<ll>> M(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i)
		M[i][i] = 1;
	return M;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> A, ll k) {
	auto B = k > 0 ? --k, A : matrixIdentity(A.size());
	for (; k; k >>= 1) {
		if (k & 1)
			B = matrixMult(A, B);
		A = matrixMult(A, A);
	}
	return B;
}

ll extGCD(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	ll q = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return q;
}

namespace BSGS {
ll qpow(ll a, ll b, const ll p) {
	ll res = 1;
	while (b) {
		if (b & 1)
			(res *= a) %= p;
		(a *= a) %= p;
		b >>= 1;
	}
	return res;
}

ll inv(const ll x, const ll p) {
	return qpow(x, p - 2, p);
}

// Baby Step Giant Step
// Discrete log base a of b mod p
ll bsgs(ll a, ll b, const ll p) {
	a = (a % p + p) % p;
	b = (b % p + p) % p;

	const ll u = (ll) sqrt(p) + 1;

	map<ll, ll> tab;
	ll now = 1;
	for (ll i = 0; i < u; i++) {
		const ll tmp = b * inv(now, p) % p;
		if (!tab.count(tmp))
			tab[tmp] = i;
		(now *= a) %= p;
	}
	const ll step = now;
	now = 1;
	for (ll i = 0; i < p; i += u) {
		if (tab.count(now))
			return i + tab[now];
		(now *= step) %= p;
	}
	assert(false);
	return -1;
}
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

ll q(const ll x) {
	ll res = BSGS::bsgs(3, x, mod);
	assert((modPow(3, res) - x) % mod == 0);
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int k;
	cin >> k;
	vector<ll> b(k);
	for (ll &x : b)
		cin >> x;

	vector<vector<ll>> M(k, vector<ll>(k, 0));
	for (int i = 1; i < k; ++i)
		M[i][i - 1] = 1;
	for (int i = 0; i < k; ++i)
		M[i][k - 1] = b[k - 1 - i];

	vector<vector<ll>> u(1, vector<ll>(k, 0));
	u.back().back() = 1;

	ll n, m;
	cin >> n >> m;
	M = matrixPow(M, n - 1);
	u = matrixMult(u, M);

	const ll pw = u[0][0];

	DBG(pw)

	const ll q_m = q(m);

	ll q_x = 0, _y = 0;
	const ll g = extGCD(pw, mod - 1, q_x, _y);

	assert(q_x * pw + _y * (mod - 1) == g);

	if (q_m % g) {
		cout << -1;
		return 0;
	}

	q_x %= mod - 1;
	if (q_x < 0)
		q_x += mod - 1;

	q_x *= q_m / g;
	q_x %= mod - 1;

	cout << modPow(3, q_x) << endl;
	assert((q_x * pw - q_m) % (mod - 1) == 0);

	return 0;
}