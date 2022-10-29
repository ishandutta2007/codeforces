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

const int Mod = 998244353;

template <const int Mod = :: Mod>
class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		friend Z operator + (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		friend Z operator - (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v - b.v) < 0) ? (x + Mod) : (x));
		}
		friend Z operator * (const Z& a, const Z& b) {
			return Z(a.v * 1ll * b.v);
		}
		friend Z operator ~(const Z& a) {
			return inv(a.v, Mod);
		}
		friend Z operator - (const Z& a) {
			return Z(0) - a;
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
		friend boolean operator == (const Z& a, const Z& b) {
			return a.v == b.v;
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

const int V = 64;

typedef class Matrix {
	public:
		int r, c;
		Zi a[64][64];
		
		Zi* operator [] (int p) {
			return a[p];
		}

		Matrix operator * (Matrix b) {
			Matrix rt;
			assert(c == b.r);
			memset(rt.a, 0, sizeof(rt.a));
			rt.r = r, rt.c = b.c;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < b.c; j++) {
					for (int k = 0; k < c; k++) {
						rt[i][k] += a[i][j] * b[j][k];
					}
				}
			}
			return rt;
		}
		Matrix operator + (Matrix b) {
			Matrix rt;
			rt.r = r, rt.c = c;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					rt[i][j] = a[i][j] + b[i][j];	
				}
			}
			return rt;
		}
} Matrix;

const int N = 1e3 + 5;

int n, m;
int a[N];
int ban[4];
Matrix G[4];
Matrix pw[33];

int mex(int s, int ban) {
	static boolean vis[5];
	memset(vis, 0, sizeof(vis));
	int sg = 0;
	for (int i = 0; i < 3; i++) {
		if ((ban >> i) & 1) {
			vis[(s >> (i << 1)) & 3] = true;
		}
	}
	while (vis[sg]) sg++;
	return sg;
}
int lshift(int s) {
	return (s << 2) & 63;
}

#define pii pair<int, int>

Matrix f;
Zi g[N][5], h[5];
vector<pii> cs[N];

void trans(Matrix& x, int len) {
	for (int i = 0; i <= 30; i++) {
		if ((len >> i) & 1) {
			x = x * pw[i];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	scanf("%d", &m);
	for (int i = 1, x, y, c; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &c);
		cs[x].emplace_back(y, c);
	}
	for (int i = 1; i <= n; i++) {
		sort(cs[i].begin(), cs[i].end());
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1, x; j <= 3; j++) {
			scanf("%d", &x);
			ban[i] |= (x << (j - 1));
		}
	}
	for (int i = 1; i <= 3; i++) {
		G[i].r = G[i].c = V;
		for (int j = 0; j < V; j++) {
			int k = lshift(j) | mex(j, ban[i]);
			G[i][j][k] = 1;			
		}
	}
	G[0] = G[1] + G[2] + G[3];
	pw[0] = G[0];
	for (int i = 1; i <= 30; i++) {
		pw[i] = pw[i - 1] * pw[i - 1];
	}
	g[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		memset(f.a, 0, sizeof(f.a));
		f.r = 1, f.c = V;
		f[0][63] = 1;
		int ls = 0;
		for (auto par : cs[i]) {
			int len = par.first - ls - 1;
			trans(f, len);
			f = f * G[par.second];
			ls = par.first;
		}
		trans(f, a[i] - ls);
		memset(h, 0, sizeof(h));
		for (int j = 0; j < V; j++) {
			h[j & 3] += f[0][j];
		}
		for (int p = 0; p < 4; p++) {
			for (int q = 0; q < 4; q++) {
				g[i][p ^ q] += g[i - 1][p] * h[q];
			}
		}
	}
	Zi ans = g[n][0];
	printf("%d\n", ans.v);
	return 0;
}