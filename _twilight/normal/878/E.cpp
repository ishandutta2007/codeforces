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

const int Limit = 2e9, N = 1e5 + 5, bzmax = 19, inv2 = (Mod + 1) >> 1;

int n, q;
int a[N];
Zi za[N];
int f[bzmax][N];
Zi s[N], g[bzmax][N], pw2[N];

Zi solve(int l, int r) {
	Zi rt = 0;
	for (int i = bzmax - 1; ~i; i--) {
		if (f[i][r] >= l) {
			rt += g[i][r], r = f[i][r];
		}
	}
	rt += (s[r] * pw2[r - l + 1] - s[l - 1]) * inv2;
	return rt;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		za[i] = Zi(a[i]) + Mod;
	}
	pw2[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw2[i] = pw2[i - 1] + pw2[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] * inv2 + za[i];
	}
	for (int i = 1; i <= n; i++) {
		ll cur = 0;
		Zi& sum = g[0][i];
		for (int j = i; j; j--) {
			cur = (cur * 2 + a[j]);
			sum = sum + sum + za[j];
			if (cur <= 0) {
				f[0][i] = j - 1;
				sum = sum + sum;
				break;
			} else if (cur >= Limit) {
				f[0][i] = 0;
				sum = s[i] * pw2[i];
				break;
			}
		}
	}
	for (int i = 1; i < bzmax; i++) {
		for (int j = 1; j <= n; j++) {
			if (!f[i - 1][j]) {
				g[i][j] = g[i - 1][j];
			} else {
				f[i][j] = f[i - 1][f[i - 1][j]];
				g[i][j] = g[i - 1][j] + g[i - 1][f[i - 1][j]]; 
			}
		}
	}
	int l, r;
	while (q--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", solve(l, r).v);
	}
	return 0;
}