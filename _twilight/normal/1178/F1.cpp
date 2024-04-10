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

const int N = 505;

int n, m;
int p[N];
Zi f[N][N];

Zi dp(int l, int r) {
	if (l >= r)
		return 1;
	if (f[l][r].v != -1)
		return f[l][r];
	int x = n + 1, L = r, R = l;
	for (int i = l; i <= r; i++) {
		if (p[i] < x) {
			x = p[i];
			L = i, R = i;
		} else if (p[i] == x) {
			R = i;
		}
	}
	f[l][r] = 1;
	for (int i = L; i <= R; i++) {
		if (p[i] ^ x) {
			int j = i;
			while (j <= R && (p[j] ^ x))
				j++;
			f[l][r] *= dp(i, --j);
			i = j;
		}
	} 
	Zi a = 0, b = 0;
	for (int i = l; i <= L; i++) {
		a += dp(l, i - 1) * dp(i, L - 1);
	}
	for (int i = R; i <= r; i++) {
		b += dp(R + 1, i) * dp(i + 1, r);
	}
	f[l][r] *= a * b;
	return f[l][r];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", p + i);
	}
	memset(f, -1, sizeof(f));
	Zi ans = dp(1, n);
	printf("%d\n", ans.v);
	return 0;
}