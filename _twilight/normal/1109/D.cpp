#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int Mod = 1e9 + 7;

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

typedef class Zi {
	public:
		int v;
		
		Zi() : v(0) {	}
		Zi(int v) : v(v) {	}
		Zi(ll x) : v(x % Mod) {	}

		Zi operator + (Zi b) {
			int x = v + b.v;
			return Zi((x >= Mod) ? (x - Mod) : (x));
		}
		Zi operator - (Zi b) {
			int x = v - b.v;
			return Zi((x < 0) ? (x + Mod) : (x));
		}
		Zi operator * (Zi b) {
			return Zi(v * 1ll * b.v);
		}
		Zi operator ~ () {
			return inv(v, Mod);
		}
} Zi;

Zi qpow(Zi a, int p) {
	if (p < 0)
		p += Mod - 1;
	Zi rt = 1, pa = a;
	for ( ; p; p >>= 1, pa = pa * pa) {
		if (p & 1) {
			rt = rt * pa;
		}
	}
	return rt;
}

int n, m;
Zi *fac, *_fac;

inline void init() {
	scanf("%d%d", &n, &m);
	int t = max(n, m) + 1;
	fac = new Zi[(t + 1)];
	_fac = new Zi[(t + 1)];
	fac[0] = 1;
	for (int i = 1; i <= t; i++) {
		fac[i] = fac[i - 1] * i;
	}
	_fac[t] = ~fac[t];
	for (int i = t; i; i--) {
		_fac[i - 1] = _fac[i] * i;
	}
}

Zi comb(int n, int m) {
	if (n < m)
		return 0;
	return fac[n] * _fac[m] * _fac[n - m];
}

inline void solve() {
	Zi ans = 0;
	for (int l = 2; l <= n && l - 1 <= m; l++) {
		Zi tmp = comb(n - 2, l - 2)  * fac[l - 2] * qpow(m, n - l) * comb(m - 1, l - 2) * qpow(n, n - l - 1) * l;
//		cerr << l << " " << tmp.v << '\n';
		ans = ans + tmp;
	}
	printf("%d\n", ans.v);
}

int main() {
	init();
	solve();
	return 0;
}