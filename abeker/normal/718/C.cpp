#include <cstdio>
using namespace std;

const int MAXN = 100005;
const int offset = 1 << 17;
const int MOD = 1000000007;

struct matrix {
	int mat[2][2];
	int* operator [](int x) {
		return mat[x];
	}
};

const matrix id = {1, 0, 0, 1};
const matrix fib = {1, 1, 1, 0};
const matrix zero = {0, 0, 0, 0};

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

matrix operator +(matrix A, matrix B) {
	matrix C;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			C[i][j] = add(A[i][j], B[i][j]);
	return C;
}

matrix operator *(matrix A, matrix B) {
	matrix C = zero;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
	return C;
}

void operator *=(matrix &A, matrix B) {
	A = A * B;
}

matrix operator ^(matrix A, int x) {
	matrix res = id;
	for (; x; x /= 2) {
		if (x % 2) res *= A;
		A *= A; 
	}
	return res;
}

int N, M;
int a[MAXN];
matrix t[2 * offset], lazy[2 * offset];

void init(int x, int lo, int hi) {
	lazy[x] = id;
	if (hi - lo == 1) {
		t[x] = fib ^ a[lo];
		return;
	}
	int mid = (lo + hi) / 2;
	init(2 * x, lo, mid);
	init(2 * x + 1, mid, hi);
	t[x] = t[2 * x] + t[2 * x + 1];
}

void prop(int x) {
	t[2 * x] *= lazy[x];
	lazy[2 * x] *= lazy[x];
	t[2 * x + 1] *= lazy[x];
	lazy[2 * x + 1] *= lazy[x];
	lazy[x] = id;
}

void update(int x, int lo, int hi, int from, int to, matrix val) {
	if (lo >= to || hi <= from) return;
	if (lo >= from && hi <= to) {
		t[x] *= val;
		lazy[x] *= val;
		return;
	}
	prop(x);
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, val);
	update(2 * x + 1, mid, hi, from, to, val);
	t[x] = t[2 * x] + t[2 * x + 1];
}

matrix query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from) return zero;
	if (lo >= from && hi <= to) return t[x];
	prop(x);
	int mid = (lo + hi) / 2;
	return query(2 * x, lo, mid, from, to) + query(2 * x + 1, mid, hi, from, to);
}

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

void solve() {
	init(1, 0, offset);
	while (M--) {
		int tp, l, r, x;
		scanf("%d%d%d", &tp, &l, &r);
		if (tp == 1) {
			scanf("%d", &x);
			update(1, 0, offset, l, r + 1, fib ^ x);
		}
		else printf("%d\n", query(1, 0, offset, l, r + 1)[0][1]);
	}
}

int main() {
	load();
	solve();
	return 0;
}