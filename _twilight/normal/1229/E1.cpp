#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 6, M = 7, S = 4e3 + 3, Mod = 1e9 + 7;

#define ll long long
#define ull unsigned long long

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

int n, m;
int cnt;
int tr[S][64];
vector<ull> st;
map<ull, int> G;

int dfs(ull s) {
	if (G.count(s)) {
		return G[s];
	}
	G[s] = cnt;
	st.push_back(s);
	int cur = cnt++;
	for (int t = 0; t < (1 << n); t++) {
		ull ns = s;
		for (int S = 1; S < (1 << n); S++) {
			if ((s >> S) & 1) {
				continue;
			}
			int T = S & t;
			for (int i = 0; i < n; i++) {
				if (((T >> i) & 1) && ((s >> (S ^ (1 << i))) & 1)) {
					ns |= 1ull << S;
					break;
				}
			} 
		}
		tr[cur][t] = dfs(ns);
	}
	return cur;
}

Zi c[1 << N];
int bit[1 << N];
Zi f[2][S], P[N][M];
int main() {
	scanf("%d", &n);
	m = n;
	dfs(1);
	Zi inv100 = ~Zi(100);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &P[i][j].v);
			P[i][j] *= inv100;
		}
	}
	int cur = 0;
	f[0][0] = 1;
	for (int i = 0; i < m; i++) {
		memset(f[cur ^ 1], 0, sizeof(f[0]));
		for (int j = 0; j < (1 << n); j++) {
			c[j] = 1;
			for (int k = 0; k < n; k++) {
				if ((j >> k) & 1) {
					c[j] = c[j] * P[k][i];
				} else {
					c[j] = c[j] * (Zi(1) - P[k][i]);
				}
			}
		}
		for (int j = 0; j < cnt; j++) {
			Zi v = f[cur][j];
			if (!v.v) continue;
			for (int s = 0; s < (1 << n); s++) {
				f[cur ^ 1][tr[j][s]] += v * c[s];
			}
		}
		cur ^= 1;
	}
	bit[0] = 0;
	for (int i = 1; i < (1 << n); i++) {
		bit[i] = bit[i >> 1] + (i & 1);
	}
	Zi ans = 0;
	if (n < 6) {
		ans = f[cur][G[((1ull << (1 << n)) - 1)]];
	} else {
		ans = f[cur][G[~0ull]];
	}
	printf("%d\n", ans.v);
	return 0;
}