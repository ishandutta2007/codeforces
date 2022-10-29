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

const int N = 5005;

Zi Inv[N];
void init_inv(int n) {
	Inv[0] = 0, Inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		Inv[i] = Inv[Mod % i] * Zi((Mod - (Mod / i)));
	}
}

int n;
Zi ans;
int a[N], c[N];
Zi f[N][N], g[N][N];

int main() {
	scanf("%d", &n);
	init_inv(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		c[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
		c[i] += c[i - 1];
	for (int i = 0; i <= n; i++)
		g[0][i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (c[j] - c[j - 1]) {
				int x = c[j] - c[j - 1];
				f[i][j] = g[i - 1][j - 1] * x * Inv[n - i + 1];
				ans += f[i - 1][j] * (x - 1) * Inv[n - i + 1];
			}
		}
		for (int j = 1; j <= n; j++) {
			g[i][j] = g[i][j - 1] + f[i][j];
		}
	}
	printf("%d\n", ans.v);
	return 0;
}