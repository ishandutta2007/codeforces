#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int LOG = 64;

struct matrix {
	int n;
	int a[LOG][LOG];
	
	matrix(int _n) {
		n = _n;
		memset(a, 0, sizeof a);
	}
	
	void identity() {
		for (int i = 0; i < n; i++)
			a[i][i] = 1;
	}
	
	int* operator [](int x) {
		return a[x];
	}
};

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

matrix operator *(matrix A, matrix B) {
	assert(A.n == B.n);
	matrix C(A.n);
	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < A.n; j++)
			for (int k = 0; k < A.n; k++)
				C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
	return C;
}

matrix operator ^(matrix A, int k) {
	matrix C(A.n);
	C.identity();
	for (; k; k /= 2) {
		if (k % 2)
			C = C * A;
		A = A * A;
	}
	return C;
}

ll N;
int K;
int inv[LOG];

void load() {
	scanf("%lld%d", &N, &K);
}

int calc(int prime, int ex) {
	matrix P(ex + 1);
	for (int i = 0; i <= ex; i++)
		for (int j = 0; j <= i; j++)
			P[i][j] = inv[i + 1];
	P = P ^ K;
	int res = 0, prod = 1;
	for (int i = 0; i <= ex; i++) {
		res = add(res, mul(P[ex][i], prod));
		prod = mul(prod, prime);
	}
	return res;
}

int solve() {
	for (int i = 1; i < LOG; i++)
		inv[i] = pot(i, MOD - 2);
		
	int sol = 1;
	for (ll i = 2; i * i <= N; i++) {
		if (N % i)
			continue;
		int ex = 0;
		for (; !(N % i); N /= i)
			ex++;
		sol = mul(sol, calc(i % MOD, ex));
	}
	if (N > 1)
		sol = mul(sol, calc(N % MOD, 1));
		
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}