#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 150005;

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

typedef class Fenwick {
	public:
		int n;
		Zi* a;

		void init(int s) {
			this->n = s;
			a = new Zi[(s + 1)];
		}
		void add(int idx, Zi x) {
			for ( ; idx <= n; idx += (idx & (-idx)))
				a[idx] += x;
		}
		void add(int l, int r, Zi x) {
			add(l, x), add(r + 1, -x);
		}
		Zi query(int idx) {
			Zi rt = 0;
			for ( ; idx; idx -= (idx & (-idx)))
				rt += a[idx];
			return rt;
		}
} Fenwick;

int n, m;
vector<int> G[N];

int sz[N], zson[N], fa[N];
int in[N], out[N], top[N];

void dfs1(int p, int fa) {
	sz[p] = 1, ::fa[p] = fa;
	int mx = 0, &id = zson[p];
	for (auto e : G[p]) {
		if (e ^ fa) {
			dfs1(e, p);
			sz[p] += sz[e];
			if (sz[e] > mx) {
				mx = sz[e];
				id = e;
			}
		}
	}
}

void dfs2(int p, boolean ontop) {
	static int dfc = 0;
	in[p] = ++dfc;
	top[p] = (ontop) ? (p) : top[fa[p]];
	if (zson[p])
		dfs2(zson[p], false);
	for (auto e : G[p]) {
		if (e != fa[p] && e != zson[p]) {
			dfs2(e, true);
		}
	}
	out[p] = dfc;
}

Zi tg[N];
Fenwick fen;

Zi query(int p) {
	int q;
	Zi ret = 0;
	while ((p = top[p], q = fa[p])) {
		ret += tg[q] * (n - sz[p]);
		p = q;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, true);
	
	Zi sum = 0;
	fen.init(n);
	int op, x, y;
	Zi invn = ~Zi(n);
	while (m--) {
		scanf("%d%d", &op, &x);
		if (op == 1) {
			scanf("%d", &y);
			sum += Zi(y) * sz[x];
			tg[x] += y;
			fen.add(in[x], out[x], -Zi(y) * sz[x]);
			if (zson[x]) {
				x = zson[x];
				fen.add(in[x], out[x], Zi(y) * (n - sz[x]));
			}
		} else {
			Zi ans = sum;
			ans += query(x);
			ans += fen.query(in[x]);
			ans = ans * invn + tg[x];
			printf("%d\n", ans.v);
		}
	}
	return 0;
}