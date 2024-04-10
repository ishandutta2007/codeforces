#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll N, M;
	cin >> N >> M;

	vector<vector<ll>> v = { vector<ll>(M, 1) };

	vector<vector<ll>> A(M, vector<ll>(M, 0));
	A[0][M - 1] = 1;
	A[M - 1][M - 1] = 1;
	for (int i = 1; i < M; ++i)
		A[i][i - 1] = 1;

	if (N < M) {
		cout << 1;
		return 0;
	}
	v = matrixMult(v, matrixPow(A, N - M + 1));
	cout << v.back().back();
	return 0;
}