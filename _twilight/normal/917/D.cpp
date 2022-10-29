#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}

int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : (x);
}

const int Mod = 1e9 + 7;

template <const int Mod = :: Mod>
class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		Z operator + (Z b) {
			int x;
			return Z(((x = v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		Z operator - (Z b) {
			int x;
			return Z(((x = v - b.v) < 0) ? (x + Mod) : (x));
		}
		Z operator * (Z b) {
			return Z(v * 1ll * b.v);
		}
		Z operator ~() {
			return inv(v, Mod);
		}
		Z operator - () {
			return Z(0) - *this;
		}
		Z& operator += (Z b) {
			return *this = *this + b;
		}
		Z& operator -= (Z b) {
			return *this = *this - b;
		}
		Z& operator *= (Z b) {
			return *this = *this * b;
		}
};

Z<> qpow(Z<> a, int p) {
	Z<> rt = Z<>(1), pa = a;
	for ( ; p; p >>= 1, pa = pa * pa) {
		if (p & 1) {
			rt = rt * pa;
		}
	}
	return rt;
}

typedef Z<> Zi;

const int N = 105;

typedef class Matrix {
	public:
		int n;
		Zi a[N][N];

		Zi* operator [] (int p) {
			return a[p];
		}

		Zi guass() {
			Zi ret = 1, div = 1;
			for (int i = 0, c = -1; i < n; i++, c = -1) {
				for (int j = i; j < n && c == -1; j++) {
					if (a[j][i].v) {
						c = j;
					}
				} 
				if (c == -1) {
					return 0;
				}
				if (i ^ c) {
					for (int j = 0; j < n; j++) {
						swap(a[i][j], a[c][j]);
					}
					ret = Mod - ret.v;
				}
				for (int j = i + 1; j < n; j++) {
					Zi x = a[j][i], y = a[c][i];
					div *= y;
					for (int k = 0; k < n; k++) {
						a[j][k] = a[j][k] * y -  a[c][k] * x;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				ret *= a[i][i];
			}
			return ret * (~div);
		}
} Matrix;

typedef vector<Zi> Poly;

Poly operator * (Poly a, Poly b) {
	Poly rt (a.size() + b.size() - 1, Zi(0));
	for (int i = 0; i < (signed) a.size(); i++) {
		for (int j = 0; j < (signed) b.size(); j++) {
			rt[i + j] += a[i] * b[j];
		}
	}
	return rt;
}

Poly& operator *= (Poly& a, Zi x) {
	for (int i = 0; i < (signed) a.size(); i++) {
		a[i] *= x;
	}
	return a;
} 

Poly operator + (Poly a, Poly b) {
	int n = max(a.size(), b.size());
	a.resize(n), b.resize(n);
	for (int i = 0; i < n; i++) {
		a[i] += b[i];
	}
	return a;
}

Poly Lagrange(Zi *y, int n) {
	Poly rt (n, 0);
	for (int i = 0; i < n; i++) {
		Poly tmp ({Zi(1)});
		Zi fac = 1;
		for (int j = 0; j < n; j++) {
			if (i ^ j) {
				tmp = tmp * Poly({- Zi(j + 1), Zi(1)});
				fac = fac * (Zi(i) - Zi(j));
			}
		}
		fac = ~fac * y[i];
		tmp *= fac;
		rt = rt + tmp;
	}
	return rt;
}

#define pii pair<int, int>

int n;
Poly g;
Zi v[N];
Matrix A;
vector<pii> E;

inline void init() {
	scanf("%d", &n);
	A.n = n - 1;
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		E.push_back(pii(--u, --v));
	}
}

inline void solve() {
	int _n = n - 1;
	for (int i = 0; i < n; i++) {
		A.n = _n;
		for (int j = 0; j < _n; j++) {
			for (int k = 0; k < _n; k++) {
				if (j == k) {
					A[j][j] = _n;
				} else {
					A[j][k] = Mod - 1;
				}
			}
		}
		for (auto e : E) {
			int u = e.first, v = e.second;
			(u < _n) ? (A[u][u] += i) : (0);
			(v < _n) ? (A[v][v] += i) : (0);
			if (u < _n && v < _n) {
				A[u][v] -= i, A[v][u] -= i;
			}
		}
		v[i] = A.guass();
	}
	g = move(Lagrange(v, n));
	for (int i = 0; i < n; i++) {
		printf("%d ", g[i].v);
	}
}

int main() {
	init();
	solve();
	return 0;
}