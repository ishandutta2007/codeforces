#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e3 + 5;

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

int n, m, C;
Zi ans[N];
int a[N], c[N];
Zi g[N][N], h[N];
Zi pw2[N], spw2[N], _spw2[N];

void dp1() {
	static Zi f[N][N];	
	spw2[0] = 0, pw2[0] = 1;
	for (int i = 1; i <= n; i++)
		pw2[i] = pw2[i - 1] + pw2[i - 1];
	for (int i = 1; i <= n; i++)
		spw2[i] = spw2[i - 1] + spw2[i - 1] + 1;
	for (int i = 1; i <= n; i++)
		_spw2[i] = ~spw2[i];
	for (int l = 1; l <= n; l++) {
		memset(c, 0, (C + 1) << 2);
		int cnt = 0;
		Zi v = 1;
		for (int r = l; r <= n; r++) {
			int& cr = c[a[r]];
			if (!c[a[r]]) {
				cnt++, cr = 1;
			} else {
				cr++;
				v = v * _spw2[cr - 1] * spw2[cr];
			}
			if (cnt == C && a[l] != a[r]) {
				g[l][r] = v * _spw2[c[a[l]]] * pw2[c[a[l]] - 1] * _spw2[cr];
			} else if (cnt == C && l == r) {
				g[l][r] = 1;
			}
		}
		v = v * (cnt == C);
		h[l] = pw2[n - l + 1] - v;
	}
	/* for (int l = 1; l <= n; l++, cerr << '\n') {
		for (int r = 1; r <= n; r++) {
			cerr << g[l][r].v << ' ';
		}
	} */
	h[n + 1] = 1;
	/* for (int i = 1; i <= n; i++) {
		cerr << i << " " << h[i].v << '\n';
	} */
	for (int r = 1; r <= n; r++) {
		for (int l = 1; l <= r; l++) {
			g[l][r] += g[l - 1][r];
		}
	}
	f[0][0] = 1;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			Zi v = f[i][j];
			if (!v.v) {
				continue;
			}
			for (int r = j + 1; r <= n; r++) {
				f[i + 1][r] += v * (g[r][r] - g[j][r]);
			}
			ans[i] += v * h[j + 1];
		}
	}
}

void dp2() {
	int M = (m + 1) * (1 << C), S = (1 << C) - 1;
	Zi *fcur = new Zi[M];
	Zi *fnxt = new Zi[M];
	for (int i = 1; i <= n; i++) {
		a[i]--;
	}
	memset(fcur, 0, M << 2);
	fcur[0] = 1;
	for (int i = 1; i <= n; i++) {
		memset(fnxt, 0, M << 2);
		for (int j = 0; j <= m; j++) {
			for (int s = 0; s < S; s++) {
				Zi v = fcur[j << C | s];
				if (v.v) {
					fnxt[j << C | s] += v;
					if ((s | (1 << a[i])) < S) {
						fnxt[j << C | (s | (1 << a[i]))] += v;
					} else if (j < m) {
						fnxt[(j + 1) << C] += v;
					}
				}
			}
		}
		swap(fcur, fnxt);
	}
	for (int i = 0; i < M; i++) {
		ans[i >> C] += fcur[i];
	}
}

int main() {
	scanf("%d%d", &n, &C);
	m = n / C;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	if (C <= 20 && (1 << C) <= n) {
		dp2();
	} else {
		dp1();
	}
	ans[0] -= 1;
	for (int i = 0; i <= n; i++) {
		printf("%d ", ans[i].v);
	}
	return 0;
}