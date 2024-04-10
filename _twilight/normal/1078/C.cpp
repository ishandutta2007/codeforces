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

ostream& operator << (ostream& os, Zi z) {
	os << z.v;
	return os;
}

const int N = 3e5 + 5;

int n;
Zi f[N][4];	// 0 : don't in any match, 1 : low, 2 : up, 3 : up (not finished)
vector<int> G[N];

void dfs(int p, int fa) {
	static Zi tmp[4];
	f[p][0] = f[p][1] = f[p][3] = 1;
	for (auto& e : G[p]) {
		if (e == fa) {
			continue;
		}
		dfs(e, p);
		tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0;
		tmp[0] += f[p][0] * (f[e][0] + f[e][2]);
		tmp[1] += f[p][1] * (f[e][0] + f[e][2] * 2);
		tmp[2] += f[p][2] * (f[e][0] + f[e][2] * 2);
		tmp[3] += f[p][3] * (f[e][0] + f[e][2] * 2);
		tmp[2] += f[p][3] * f[e][1];
		f[p][0] = tmp[0], f[p][1] = tmp[1];
		f[p][2] = tmp[2], f[p][3] = tmp[3];
	}
//	cerr << p << " " << f[p][0] << " " << f[p][1] << " " << f[p][2] << '\n';
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	Zi ans = f[1][0] + f[1][2];
	printf("%d\n", ans.v);
	return 0;
}