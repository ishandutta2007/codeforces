#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = (int) 1e9 + 7;

vector<vector<ll>> matrixMult(const vector<vector<ll>> A, const vector<vector<ll>> B) {
	assert(!A.empty() && A[0].size() == B.size());
	vector<vector<ll>> C(A.size(), vector<ll>(B[0].size(), 0));
	for (int i = 0; i < (int) C.size(); ++i)
		for (int j = 0; j < (int) C[0].size(); ++j)
			for (int k = 0; k < (int) A[0].size(); ++k)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
	return C;
}

vector<vector<ll>> matrixIdentity(const int n) {
	vector<vector<ll>> M(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i)
		M[i][i] = 1;
	return M;
}

vector<vector<ll>> matrixPow(vector<vector<ll>> A, ll k) {
	auto B = matrixIdentity(A.size());
	for (; k; k >>= 1) {
		if (k & 1)
			B = matrixMult(A, B);
		A = matrixMult(A, A);
	}
	return B;
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
ll C2(ll x) {
	x %= mod;
	return x * (x - 1) / 2 % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, K, B = 0, I;
	cin >> N >> K;

	{
		vector<int> a(N);
		for (int &x : a) {
			cin >> x;
			B += x;
		}
		I = accumulate(a.end() - B, a.end(), 0);
	}

	vector<vector<ll>> M(B + 1, vector<ll>(B + 1, 0));

	for (ll i = 0; i <= B; ++i) {
		M[i][i] = C2(B) + C2(N - B) + (B - i) * (N - 2 * B + i) % mod + (B - i) * i % mod;
		if (i > 0)
			M[i][i - 1] = i * (N - 2 * B + i) % mod;
		if (i < B)
			M[i][i + 1] = (B - i) * (B - i) % mod;
	}

	for (int i = 0; i <= B; ++i)
		for (int j = 0; j <= B; ++j) {
			M[i][j] %= mod;
			M[i][j] *= modInv(C2(N));
			M[i][j] %= mod;
		}

	cerr << "test" << endl;
	vector<vector<ll>> v(1, vector<ll>(B + 1, 0));
	v[0][I] = 1;
	cerr << "test" << endl;

	M = matrixPow(M, K);
	cerr << "test" << endl;
	v = matrixMult(v, M);
	cerr << "test" << endl;

	cout << (v[0][B] % mod + mod) % mod;
	return 0;
}