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

const int M = 3e3 + 5, N = 2e5 + 5;

int n, m;
int a[N], w[N];
int sw, sumu, sumd;
Zi f[M][M], g[M][M];
Zi *dsum, _dsum[M << 1];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", w + i);
		((a[i]) ? (sumu) : (sumd)) += w[i];
		sw += w[i];
	}
	for (int i = max(0, m - sw); i <= (m << 1); i++) {
		_dsum[i] = ~Zi(sw + i - m);
	}
	dsum = _dsum + m;

	// for up
	sumu--;
	for (int u = m - 1; ~u; u--) {
		for (int d = m - u - 1; ~d; d--) {
			f[u][d] += f[u + 1][d] * dsum[u - d] * (sumu + u);
			f[u][d] += f[u][d + 1] * dsum[u - d] * (sumd - d);
			f[u][d] += (f[u + 1][d] * 2 + 1) * dsum[u - d];
		}
	}
	sumu++;

	// for down
	g[0][0] = 1;
	sumd--;
	Zi vd = 0;
	for (int u = 0; u <= m; u++) {
		for (int d = 0; d <= m - u; d++) {
			if (u) {
				g[u][d] += g[u - 1][d] * dsum[u - d - 1] * (sumu + u - 1);
			}
			if (d) {
				g[u][d] += g[u][d - 1] * dsum[u - d + 1] * (sumd - (d - 1));
			}
			if (u + d == m) {
				vd += g[u][d];
			}
		}
	}
	sumd++;
	
	f[0][0] += 1;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			printf("%d\n", (f[0][0] * w[i]).v);
		} else {
			printf("%d\n", (vd * w[i]).v);
		}
	}
	return 0;
}