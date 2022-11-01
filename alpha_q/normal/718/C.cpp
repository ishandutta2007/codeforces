#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

struct matrix {
	long long mat[2][2];

	matrix operator + (const matrix &b) const {
		matrix c;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				c.mat[i][j] = (mat[i][j] + b.mat[i][j]) % MOD;
		return c;
	}

	matrix operator * (const matrix &b) const {
		matrix c;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j) {
				c.mat[i][j] = 0;
				for (int k = 0; k < 2; ++k)
					c.mat[i][j] = (c.mat[i][j] + mat[i][k] * b.mat[k][j]) % MOD;
			}
		return c;
	}
};

int n, m;
long long a[N];
matrix t[4 * N], lazy[4 * N], base, unit;

bool isUnit (matrix &a) {
	return a.mat[0][0] == 1 and a.mat[1][0] == 0 and a.mat[0][1] == 0 and a.mat[1][1] == 1;
}

matrix power (matrix a, long long e) {
	e %= (MOD - 1);
	matrix res = unit;

	while (e) {
		if (e & 1) res = res * a;
		a = a * a;
		e >>= 1;
	}

	return res;
}

void propagate (int u, int b, int e) {
	t[u] = t[u] * lazy[u];

	if (b != e) {
		lazy[u << 1] = lazy[u << 1] * lazy[u];
		lazy[u << 1 | 1] = lazy[u << 1 | 1] * lazy[u];
	}

	lazy[u] = unit;
}

void build (int u, int b, int e) {
	if (b == e) {
		t[u] = power(base, a[b]);
		lazy[u] = unit;
		return;
	}

	int l = u << 1, r = l | 1, m = b + e >> 1;
	build(l, b, m), build(r, m + 1, e);
	t[u] = t[l] + t[r];
	lazy[u] = unit;
}

void update (int u, int b, int e, int p, int q, matrix v) {
	if (not isUnit(lazy[u])) propagate(u, b, e);
	if (b > q or e < p) return;
	if (b >= p and e <= q) {
		lazy[u] = lazy[u] * v;
		propagate(u, b, e);
		return;
	}

	int l = u << 1, r = l | 1, m = b + e >> 1;
	update(l, b, m, p, q, v), update(r, m + 1, e, p, q, v);
	t[u] = t[l] + t[r];
}

long long query (int u, int b, int e, int p, int q) {
	if (b > q or e < p) return 0;
	if (not isUnit(lazy[u])) propagate(u, b, e);
	if (b >= p and e <= q) return t[u].mat[1][0];

	int l = u << 1, r = l | 1, m = b + e >> 1;
	return (query(l, b, m, p, q) + query(r, m + 1, e, p, q)) % MOD; 
}

int main (int argc, char const *argv[]) {
	unit.mat[0][0] = unit.mat[1][1] = 1, unit.mat[0][1] = unit.mat[1][0] = 0;
	base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1, base.mat[1][1] = 0;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	build(1, 1, n);
	
	// for (int i = 1; i <= 25; ++i) cout << "(" << i << " : " << t[i].mat[1][0] << "), "; cout << endl;

	while (m--) {
		int cmd, l, r;
		scanf("%d %d %d", &cmd, &l, &r);

		if (cmd == 1) {
			long long x; scanf("%lld", &x);
			matrix v = power(base, x);
			update(1, 1, n, l, r, v);

			// for (int i = 1; i <= 25; ++i) cout << "(" << i << " : " << t[i].mat[1][0] << "), "; cout << endl;
		} else {
			printf("%lld\n", query(1, 1, n, l, r));
		}
	}
	return 0;
}