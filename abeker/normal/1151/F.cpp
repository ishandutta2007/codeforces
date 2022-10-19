#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MOD = 1e9 + 7;

int N, K;
int arr[MAXN];

struct matrix {
	int a[MAXN][MAXN];
	matrix() {
		memset(a, 0, sizeof a);
	}
	int* operator [](int x) {
		return a[x];
	}
};

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
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
	matrix C;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			for (int k = 0; k <= N; k++)
				C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
	return C;
}

matrix operator ^(matrix A, int n) {
	matrix B;
	for (int i = 0; i <= N; i++)
		B[i][i] = 1;
	for (; n; n /= 2) {
		if (n % 2)
			B = B * A;
		A = A * A;
	}
	return B;
}

int choose(int n) {
	return n * (n - 1) / 2;
}

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
}

int solve() {
	int zeroes = 0, inter = 0;
	for (int i = 0; i < N; i++)
		zeroes += !arr[i];
	for (int i = 0; i < zeroes; i++)
		inter += !arr[i];
	
	matrix trans;
	int inv = pot(choose(N), MOD - 2);
	for (int i = 0; i <= N; i++) {
		int in[2] = {zeroes - i, i};
		int out[2] = {N - 2 * zeroes + i, zeroes - i};
		if (in[0] < 0 || out[0] < 0)
			continue;
		trans[i][i] = mul(choose(zeroes) + choose(N - zeroes), inv);
		for (int k = 0; k < 2; k++)
			for (int l = 0; l < 2; l++)
				if (i - k + l >= 0)
					trans[i][i - k + l] = add(trans[i][i - k + l], mul(mul(in[k], out[l]), inv));
	}
	
	return (trans ^ K)[inter][zeroes];
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}