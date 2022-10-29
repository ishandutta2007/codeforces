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

const int N = 2e5 + 5;

int n;
int fa[N];
Zi f[N][3], g[3];
boolean nonleaf[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i > 1) {
			scanf("%d", fa + i);
			nonleaf[fa[i]] = true;
		}
		f[i][0] = 1;
	}
	for (int i = n; i; i--) {
		if (!nonleaf[i]) {
			f[i][1] = 1;
			f[i][0] = 0;
		}
		int y = fa[i];
		g[0] = f[y][0] * (f[i][1] + f[i][0]);
		g[1] = f[y][2] * (f[i][1] + f[i][2]) + f[y][1] * (f[i][0] + f[i][1] * 2 + f[i][2]);
		g[2] = f[y][0] * (f[i][1] + f[i][2]) + f[y][2] * (f[i][0] + f[i][1]);
		f[y][0] = g[0], f[y][1] = g[1], f[y][2] = g[2];
	}
	Zi ans = f[1][0] + f[1][1];
	printf("%d\n", ans.v);
	return 0;
}