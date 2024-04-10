#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

const int MAXN = 110;
int N, K;
int M;
int T;
int A[MAXN];

using mat = vector<vector<ll>>; 
ll minv(ll a, ll m = MOD) {
	return a == 1 ? a : m - minv(m % a, a) * m / a;
}

mat matmul(mat A, mat B) {
	mat C(M+1, vector<ll>(M+1));
	for (int i = 0; i <= M; i++) {
		for (int k = 0; k <= M; k++) {
			for (int j = 0; j <= M; j++) {
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] %= MOD;
			}
		}
	}
	return C;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		K += (A[i] == 0);
	}

	int init = 0;
	for (int i = 0; i < K; i++) {
		init += (A[i] == 1);
	}

	M = min(N-K, K);
	mat b(M+1, vector<ll>(M+1));
	ll denom = minv(N * (N-1) / 2);
	for (int i = 0; i <= M; i++) {
		ll pDec = ll(i) * i * denom % MOD;
		ll pInc = ll(K-i) * (N-K-i) * denom % MOD;
		ll pRest = (1LL + 2 * MOD - pDec - pInc) % MOD;
		b[i][i] = pRest;
		if (i) {
			b[i][i-1] = pDec;
		}
		if (i < M) {
			b[i][i+1] = pInc;
		}
	}

	mat res(M+1, vector<ll>(M+1));
	for (int i = 0; i <= M; i++) {
		res[i][i] = 1;
	}
	while (T) {
		if (T & 1) {
			res = matmul(res, b);
		}
		b = matmul(b, b);
		T /= 2;
	}
	cout << res[init][0] << endl;

	return 0;
}