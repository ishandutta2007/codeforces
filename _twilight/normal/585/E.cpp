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

typedef Z<> Zi;

const int V = 1e7 + 7, N = 5e5 + 5;

int n, m;
int P[44];
int a[N], c[V];

Zi pw2[N];
int pri[V];
int bk[V], mp[V];
void Euler(int n) {
	static bitset<V> bs;
	int num = 0;
	for (int i = 2; i <= n; i++) {
		if (!bs.test(i)) {
			pri[num++] = i;
			bk[i] = 1, mp[i] = i;
		}
		for (int *p = pri, *_ = pri + num, x; p != _ && (x = *p * i) <= n; p++) {
			bs.set(x);
			mp[x] = *p;
			if (i % *p) {
				bk[x] = i;
			} else {
				bk[x] = bk[i];
				break;
			}
		}
	}
}

void factorize(int x) {
	m = 0;
	for ( ; x > 1; x = bk[x]) {
		P[m++] = mp[x];
	}
}

void dfs1(int x, int prod, int sgn) {
	if (x == m) {
		c[prod] += sgn;
		return;
	}
	dfs1(x + 1, prod * P[x], -sgn);
	dfs1(x + 1, prod, sgn);
}

int _abs(int x) {
	return (x < 0) ? (-x) : (x);
}

void dfs2(int x, int prod, int sgn, Zi& dt) {
	if (x == m) {
		Zi d = pw2[_abs(c[prod])] - pw2[_abs(c[prod]) - 1];
		(sgn == 1) ? (dt += d) : (dt -= d);
		return ;
	}
	dfs2(x + 1, prod * P[x], -sgn, dt);
	dfs2(x + 1, prod, sgn, dt);
}

int main() {
	int mx = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		mx = max(a[i], mx);
	}
	Euler(mx);
	for (int i = 1; i <= n; i++) {
		factorize(a[i]);
		dfs1(0, 1, 1);
	}
	Zi all = 0;
	pw2[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw2[i] = pw2[i - 1] + pw2[i - 1];
	}
	for (int i = 1; i <= mx; i++) {
		if (c[i] > 0) {
			all += pw2[c[i]] - 1;
		} else if (c[i] < 0) {
			all -= pw2[-c[i]] - 1;
		}
	}
	Zi X = 0, dt;
	for (int i = 1; i <= n; i++) {
		factorize(a[i]);
		dfs2(0, 1, 1, dt = 0);
		X += all - dt;
	}
	Zi Y = all * n - X;
	Zi ans = Y - X;
	printf("%d\n", ans.v);
	return 0;
}