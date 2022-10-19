#include <bits/stdc++.h>
using namespace std;

#define bc __builtin_popcount

typedef pair <int, int> pii;

const int MAXS = 215;
const int MOD = 1e9 + 7;

int N, K, M, S;
map <pii, int> id;

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline void inc(int &x, int y) {
	x = add(x, y);
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

struct matrix {
	int a[MAXS][MAXS];
	matrix(int n, int diag) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = i == j ? diag : 0;
	}
	int* operator [](int x) {
		return a[x];
	}
};

matrix operator *(matrix A, matrix B) {
	matrix C(S, 0);
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			for (int k = 0; k < S; k++)
				C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
	return C;
}

matrix operator ^(matrix A, int ex) {
	matrix C(S, 1);
	for (; ex; ex /= 2) {
		if (ex % 2)
			C = C * A;
		A = A * A;
	}
	return C;
}

void load() {
	scanf("%d%d%d", &N, &K, &M);
}

void init(matrix &A, int row, int k, int mask, int val) {
	if (id.find({k, mask}) != id.end())
		inc(A[row][id[{k, mask}]], val);
}

int solve() {
	vector <pii> states;
	for (int k = 0; k <= K; k++)
		for (int i = 0; i < 1 << M; i++)
			if (bc(i) <= k) {
				id[{k, i}] = states.size();
				states.push_back({k, i});
			}
	
	S = states.size();
	matrix trans(S, 0);
	for (auto it : states) 
		for (int bit = 0; bit < 2; bit++)
			init(trans, id[it], it.first - (it.second & 1), (it.second >> 1) | (bit << M - 1), it.second & 1 ? bc(it.second) + bit : 1);
	
	int sol = 0;
	matrix final = trans ^ N;
	for (auto it : states)
		if (it.first == K)
			inc(sol, final[id[it]][0]);
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}