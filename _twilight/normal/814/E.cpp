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

const int N = 53;
const Zi inv2 ((Mod + 1) >> 1);

int n;
int d[N];
Zi fac[N];
Zi f[N][N << 1];
Zi g[N][N][N << 1];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", d + i);
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	g[0][0][0] = 1;
	for (int d2 = 0; d2 <= n; d2++) {
		for (int d1 = 0; (d1 + d2) <= n; d1++) {
			if (!(d1 + d2)) continue;
			for (int i = 0; i <= d1 + (d2 << 1); i++) {
				Zi& v = g[d1][d2][i];
				if (d2 > 0) {
					int nd2 = d2 - 1;
					if (i >= 2) v += g[d1][nd2][i - 2];
					if (i && d1) v += g[d1 - 1][nd2][i - 1] * d1 * 2;
					if (i && nd2) v += g[d1 + 1][nd2 - 1][i - 1] * nd2 * 4;
					if (d1 >= 2) v += g[d1 - 2][nd2][i] * d1 * (d1 - 1);
					if (d1 && nd2) v += g[d1][nd2 - 1][i] * d1 * nd2 * 4;
					if (nd2 >= 2) v += g[d1 + 2][nd2 - 2][i] * nd2 * 2 * (nd2 * 2 - 2);
				} else {
					if (i >= 1) v += g[d1 - 1][0][i - 1];
					if (d1 >= 1) v += g[d1 - 2][0][i] * (d1 - 1);
				}
			}
		}
	}
	f[1][d[1]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= (i << 1) + 1 && i + j <= n; j++) {
			Zi v = f[i][j] * fac[j];
			if (!v.v) {
				continue;
			}
			int l = i + 1, r = i + j, c1 = 0, c2 = 0;
			for (int k = l; k <= r; k++) {
				(d[k] == 2) ? (c1++) : (c2++);
			}
			for (int k = 0; k <= (c1 + (c2 << 1)); k++) {
				f[r][k] += v * g[c1][c2][k];
			}
		}
	}
	
	Zi prod = fac[d[1]];
	for (int i = 2; i <= n; i++)
		prod *= d[i] - 1;
	Zi ans = f[n][0] * ~prod;

	printf("%d\n", ans.v);
	return 0;
}