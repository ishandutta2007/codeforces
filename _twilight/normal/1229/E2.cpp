#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 7, M = 8, S = 65000, Mod = 1e9 + 7;

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

typedef class int128_t {
	public:
		unsigned long long x[2];

		boolean test(int p) {
			return (x[p >> 6] >> (p & 63)) & 1;
		}
		void set(int p) {
			x[p >> 6] |= 1ull << (p & 63);
		}
		boolean operator < (int128_t b) const {
			return (x[1] == b.x[1]) ? (x[0] < b.x[0]) : (x[1] < b.x[1]);
		}
		int128_t operator & (int128_t b) const {
			int128_t rt;
			rt.x[0] = x[0] & b.x[0];
			rt.x[1] = x[1] & b.x[1];
			return rt;
		}
		int128_t operator | (int128_t b) const {
			int128_t rt;
			rt.x[0] = x[0] | b.x[0];
			rt.x[1] = x[1] | b.x[1];
			return rt;
		}
		boolean nonzero() {
			return x[0] || x[1];
		}
} int128_t;

int n, m;
int cnt;
int tr[S][128];
vector<int128_t> st;
map<int128_t, int> G;

int128_t msk[128][128];

void prepare() {
	for (int T = 0; T < (1 << n); T++) {
		for (int S = 1; S < (1 << n); S++) {
			int128_t &f = msk[T][S];
			for (int i = 0; i < n; i++) {
				if (((T >> i) & 1)) {
					f.set((S ^ (1 << i)));
				}
			}
		}
	}
}
int dfs(int128_t s) {
	if (G.count(s))
		return G[s];
	G[s] = cnt;
	st.push_back(s);
	int cur = cnt++;
	int128_t msk[N];
	for (int i = 0; i < n; i++) {
		int128_t& f = msk[i];
		f.x[0] = 1, f.x[1] = 0;
		for (int S = 1; S < (1 << n); S++) {
			if ((s & ::msk[1 << i][S]).nonzero()) {
				f.set(S);
			}
		}
	}
	for (int t = 0; t < (1 << n); t++) {
		int128_t ns = s;
		for (int i = 0; i < n; i++) {
			if ((t >> i) & 1) {
				ns = ns | msk[i];
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
	prepare();
	int128_t _;
	_.x[0] = 1, _.x[1] = 0;
	dfs(_);
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
	int128_t all;
	all.x[0] = all.x[1] = 0;
	for (int i = 0; i < (1 << n); i++)
		all.set(i);
	ans = f[cur][G[all]];
	printf("%d\n", ans.v);
	return 0;
}