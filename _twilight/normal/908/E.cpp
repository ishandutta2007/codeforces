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

const int N = 1e3 + 5;

int m, n;
Zi B[N];
ll b[N];
Zi comb[N][N];
bitset<N> a[55];

void init(int n) {
	comb[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}
	B[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			B[i] += B[i - j] * comb[i - 1][j - 1];
		}
	}
}

void read(int id) {
	static char s[N];
	scanf("%s", s);
	for (int i = 0; i < m; i++) {
		if (s[i] == '1') {
			b[i] |= (1ll << id);
		}
	}
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		read(i);
	}
	init(m);
	Zi ans = 1;
	sort(b, b + m);
	int cnt = 1;
	for (int i = 1; i < m; i++) {
		if (b[i] == b[i - 1]) {
			cnt++;
		} else {
			ans *= B[cnt];
			cnt = 1;
		}
	}
	ans *= B[cnt];
	printf("%d\n", ans.v);
	return 0;
}