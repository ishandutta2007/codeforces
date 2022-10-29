#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

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

int gcd(int a, int b) {
	return (!b) ? (a) : (gcd(b, a % b));
}

typedef Z<> Zi;

const int N = 3e5 + 5;

int n, m;
int c[N];
Zi dp[N];

inline void init() {
	scanf("%d", &n);
	int g = 0;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		m = max(x, m);
		c[x]++;
		g = gcd(x, g);
	}
	if (g != 1) {
		puts("-1");
		exit(0);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i << 1; j <= m; j += i) {
			c[i] += c[j];
		}
	}
}

Zi binom[N];
inline void solve() {
	for (int i = 1; i <= n; i++) {
		binom[i] = 1;
	}
	for (int c = 1; ; c++) {
		Zi _c = ~Zi(c);
		binom[c - 1] = 0;
		for (int i = c; i <= n; i++) {
			binom[i] *= _c * (i - c + 1);
		}
		for (int i = m; i; i--) {
			dp[i] = binom[::c[i]];
			for (int j = i << 1; j <= m; j += i) {
				dp[i] -= dp[j];
			}
		}
		if (dp[1].v) {
			printf("%d", c);
			return;
		}
	}
	assert(false);
}

int main() {
	init();
	solve();
	return 0;
}