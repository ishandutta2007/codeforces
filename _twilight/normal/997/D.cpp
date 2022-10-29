#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 4004, Kmx = 80;

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

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

int n1, n2, K;
Zi comb[Kmx][Kmx];
Zi f[Kmx][N], g[Kmx][N];
vector<Zi> _f[Kmx][N], _g[Kmx][N];
vector<int> Tr1[N], Tr2[N];
vector<int> Gi1[N], Gi2[N];

template <vector<int> G[], vector<int> Gi[], Zi f[][N], vector<Zi> g[][N]>
void solve(int n) {
	static Zi tmp[Kmx];
	for (int i = 1; i <= n; i++) {
		f[0][i] = 1;
		g[0][i].resize(G[i].size(), Zi(1));
	}
	for (int i = 1; i <= K; i++) {
		for (int p = 1; p <= n; p++) {
			for (int k = 0; k < i; k++) {
				for (int j = 0, e; j < (signed) G[p].size(); j++) {
					e = G[p][j];
					f[i][p] += f[k][p] * g[i - k - 1][e][Gi[p][j]];
				}
			}
			g[i][p].resize(G[p].size(), Zi(0));
			pfill(tmp, tmp + i, Zi(0));
			for (int k = 0; k < i; k++) {
				for (int j = 0, e; j < (signed) G[p].size(); j++) {
					e = G[p][j];
					tmp[k] += g[k][e][Gi[p][j]];
				}
			}
			for (int j = 0, e; j < (signed) G[p].size(); j++) {
				e = G[p][j];
				for (int k = 0; k < i; k++) {
					g[i][p][j] += g[i - k - 1][p][j] * (tmp[k] - g[k][e][Gi[p][j]]);
				}
			}
		}
	}
}

inline void init_binom(int n) {
	comb[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
}

int main() {
	scanf("%d%d%d", &n1, &n2, &K);
	if (K & 1) {
		puts("0");
		return 0;
	}
	K >>= 1;
	for (int i = 1, u, v; i < n1; i++) {
		scanf("%d%d", &u, &v);
		Tr1[u].push_back(v);
		Tr1[v].push_back(u);
		Gi1[u].push_back((signed) Tr1[v].size() - 1);
		Gi1[v].push_back((signed) Tr1[u].size() - 1);
	}
	for (int i = 1, u, v; i < n2; i++) {
		scanf("%d%d", &u, &v);
		Tr2[u].push_back(v);
		Tr2[v].push_back(u);
		Gi2[u].push_back((signed) Tr2[v].size() - 1);
		Gi2[v].push_back((signed) Tr2[u].size() - 1);
	}
	solve<Tr1, Gi1, f, _f>(n1);
	solve<Tr2, Gi2, g, _g>(n2);
	init_binom(75);
	Zi ans = 0;
	/* for (int i = 0; i <= K; i++, cerr << '\n') {
		for (int j = 1; j <= n1; j++) {
			cerr << f[i][j].v << ' ';
		}
	} */
	for (int i = 0; i <= K; i++) {
		Zi s1 = 0, s2 = 0;
		for (int j = 1; j <= n1; j++) {
			s1 += f[i][j];
		}
		for (int j = 1; j <= n2; j++) {
			s2 += g[K - i][j];
		}
		ans += s1 * s2 * comb[K << 1][i << 1];
	}
	printf("%d\n", ans.v);
	return 0;
}