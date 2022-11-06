#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = (int) 1e6 + 3;
const int MxQ = 50;

ll query(const ll x) {
	assert(0 <= x && x < mod);
	cout << "? " << x << endl;

	ll resp;
	cin >> resp;
	return resp;
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

ll modInv(const ll x) {
	return modPow(x, mod - 2);
}

inline ll dotP(const vector<ll> v1, const vector<ll> v2) {
	assert(v1.size() == v2.size());
	ll res = 0;
	for (size_t i = 0; i < v1.size(); ++i)
		res += v1[i] * v2[i] % mod;
	return res % mod;
}

vector<ll> gauss(vector<vector<ll> > A) {
	const int n = (int) A[0].size() - 1;

	for (int i = 0; i < n; i++) {
		// Search for maximum in this column

		for (int k = i;; k++) {
			assert(k < (int )A.size());
			if (A[k][i]) {
				swap(A[k], A[i]);
				break;
			}
		}

		{
			const ll temp = modInv(A[i][i]);
			for (ll &x : A[i]) {
				x *= temp;
				x %= mod;
			}
		}

		// Make all rows below this one 0 in current column
		for (int k = 0; k < n; k++) {
			if (k == i)
				continue;
			const ll c = -A[k][i];
			for (int j = i; j < n + 1; j++) {
				A[k][j] += c * A[i][j];
				A[k][j] %= mod;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			const ll x = A[i][j];
			// assert(x == (i == j));
			cerr << x << ' ';
		}
		cerr << endl;
	}

	// Solve equation Ax=b for an upper triangular matrix A
	vector<ll> x(n);
	for (int i = n - 1; i >= 0; i--)
		x[i] = A[i][n];
	return x;
}

vector<ll> getVec(ll x) {
	ll curr = 1;
	vector<ll> res;
	for (int rep = 0; rep < 11; ++rep) {
		res.push_back(curr);
		curr *= x;
		curr %= mod;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	uniform_int_distribution<int> distrib(0, mod - 1);

	vector<vector<ll>> Ab;

	for (int rep = 0; rep < MxQ; ++rep) {
		const ll x = distrib(rng);
		const ll f_x = query(x);

		Ab.push_back(getVec(x));
		Ab.back().push_back(f_x);
	}

	const vector<ll> v = gauss(Ab);
	assert((int )v.size() == 11);

	for (ll x = 0; x < mod; ++x)
		if (dotP(getVec(x), v) == 0) {
			cout << "! " << x << endl;
			return 0;
		}
	cout << "! -1";
	return 0;
}