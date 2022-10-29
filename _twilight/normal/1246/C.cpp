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

const int N = 2003;

int n, m;
char s[N][N];
int c[N][N];
Zi tgr[N][N], tgc[N][N];

int qry(int x1, int y1, int x2, int y2) {
	return c[x2][y2] - c[x1 - 1][y2] - c[x2][y1 - 1] + c[x1 - 1][y1 - 1];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1] + (s[i][j] == 'R');
		}
	}
	Zi ans = 0;
	tgr[1][1] = 1, tgr[1][2] -= 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tgr[i][j] += tgr[i][j - 1];
			tgc[i][j] += tgc[i - 1][j];
			Zi valr = 0, valc = 0;
			if (qry(i, j, n, j) <= n - i)
				valr = tgr[i][j];
			if (qry(i, j, i, m) <= m - j)
				valc = tgc[i][j];
//			cerr << i << " " << j << ' ' << valr.v << " " << valc.v << '\n';
			if (i < n && j < m) {
				tgr[i + 1][j + 1] += valr + valc;
				tgr[i + 1][m + 1 - qry(i, j + 1, i, m)] -= valr;
				tgr[i + 1][m + 1 - qry(i, j, i, m)] -= valc;
				tgc[i + 1][j + 1] += valr + valc;
				tgc[n + 1 - qry(i + 1, j, n, j)][j + 1] -= valc;
				tgc[n + 1 - qry(i, j, n, j)][j + 1] -= valr;
			}
			if ((i == n || j == m) && !qry(i, j, n, m)) {
				ans += valr + valc;
			}
		}
	}
	printf("%d", ans.v);
	return 0;
}