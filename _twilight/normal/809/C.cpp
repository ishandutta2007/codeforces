#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int bzmax = 32;

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

#define pzz pair<Zi, Zi>
boolean vis[bzmax][2][2][2];
Zi F[bzmax][2][2][2], G[bzmax][2][2][2];

pzz dfs(int bit, int N1, int N2, int N3, boolean onlim1, boolean onlim2, boolean onlim3) {
	if (bit < 0) 
		return pzz(Zi(!onlim3), Zi(0));
	Zi& f = F[bit][onlim1][onlim2][onlim3], &g = G[bit][onlim1][onlim2][onlim3];
	if (vis[bit][onlim1][onlim2][onlim3])
		return pzz(f, g);
	vis[bit][onlim1][onlim2][onlim3] = true;
	f = 0, g = 0;
	pzz tmp;
	int lim1 = ((onlim1) ? ((N1 >> bit) & 1) : (1));
	int lim2 = ((onlim2) ? ((N2 >> bit) & 1) : (1));
	int lim3 = ((onlim3) ? ((N3 >> bit) & 1) : (1));
	for (int c1 = 0; c1 <= lim1; c1++) {
		for (int c2 = 0; c2 <= lim2; c2++) {
			if ((c1 ^ c2) > lim3) continue;
			tmp = dfs(bit - 1, N1, N2, N3, onlim1 && c1 == lim1, onlim2 && c2 == lim2, onlim3 && (c1 ^ c2) == lim3);
			f += tmp.first;
			g += tmp.second + tmp.first * ((c1 ^ c2) << bit);
		}
	}
	return pzz(f, g);
}

int q;
int x1, y1, x2, y2, k;

Zi solve(int x, int y) {
	pzz tmp = dfs(30, x, y, k, true, true, true);
	for (int i = 0; i <= 30; i++) {
		vis[i][1][0][0] = false;
		vis[i][1][1][0] = false;
		vis[i][1][0][1] = false;
		vis[i][1][1][1] = false;
		vis[i][0][1][0] = false;
		vis[i][0][0][1] = false;
		vis[i][0][1][1] = false;
	}
	return tmp.first + tmp.second;
}

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
		--x1, --y1, --x2, --y2;
		Zi ans = solve(x2, y2);
		if (x1) ans -= solve(x1 - 1, y2);
		if (y1) ans -= solve(x2, y1 - 1);
		if (x1 && y1) ans += solve(x1 - 1, y1 - 1);
		printf("%d\n", ans.v);
	}
	return 0;
}