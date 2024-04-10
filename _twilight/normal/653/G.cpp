#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

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

typedef Z<> Zi;

int pri[N];
int bk[N], ps[N], mp[N];
void Euler(int n) {
	static bitset<N> bs;
	int num = 0;
	for (int i = 2; i <= n; i++) {
		if (!bs.test(i)) {
			pri[num++] = i;
			bk[i] = 1, ps[i] = 1, mp[i] = i;
		}
		for (int *p = pri, *_ = pri + num, x; p != _ && (x = *p * i) <= n; p++) {
			bs.set(x);
			if (i % *p) {
				bk[x] = i, ps[x] = 1, mp[x] = *p;
			} else {
				bk[x] = bk[i], ps[x] = ps[i] + 1, mp[x] = mp[i];
				break;
			}
		}
	}
}

Zi fac[N], _fac[N];
void init_fac(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	_fac[n] = ~fac[n];
	for (int i = n; i; i--) {
		_fac[i - 1] = _fac[i] * i;
	}
}
Zi comb(int n, int m) {
	return (n < m) ? (0) : (fac[n] * _fac[m] * _fac[n - m]);
}

int n;
int c[33];
Zi ans = 0;
vector<int> P[N];
Zi f[N], g[N];
Zi f1[N], g1[N];

void solve(int p) {
	memset(c, 0, sizeof(c));
	c[0] = n;
	for (auto x : P[p]) {
		c[x]++, c[0]--;
	}
	int s = c[0], _s;
	for (int i = 1; i <= 30; i++) {
		if (c[i]) {
			_s = s + c[i];
			ans = ans + (g[_s] - g[s]) * i;
			ans = ans - (f[_s] - f[s]) * i;
			ans = ans + (f1[_s] - f1[s]) * i;
			ans = ans - (g1[_s] - g1[s]) * i;
			s = _s;
		}
	}
}

int main() {
	scanf("%d", &n);
	if (n == 1) {
		puts("0");
		return 0;
	}
	int V = 0;
	Euler(300000);
	init_fac(n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		V = max(V, x);
		for (int p; x > 1; x = bk[x]) {
			p = mp[x];
			P[p].push_back(ps[x]);
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + comb(n - 1, n - i) * (n - i + 1);
	}
	for (int i = 1; i <= n; i++) {
		g[i] = g[i - 1] + comb(n - 1, n - i);
	}
	for (int i = 1; i <= n; i++) {
		g[i] = g[i - 1] + g[i];
	}
	for (int i = 1; i <= n; i++) {
		f1[i] = f1[i - 1] + comb(n - 1, n - i - 1) * i;
	}
	for (int i = n; i; i--) {
		g1[i] = g1[i + 1] + comb(n - 1, n - i - 1);
	}
	for (int i = 1; i <= n; i++) {
		g1[i] = g1[i] + g1[i - 1];
	}
	for (int i = 2; i <= V; i++) {
		if (!P[i].empty()) {
			solve(i);
		}
	}
	printf("%d\n", ans.v);
	return 0;
}