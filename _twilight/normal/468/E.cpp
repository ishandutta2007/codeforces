#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

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

const int N = 1e5 + 5, Kmx = 53, S = 1 << 16;

#define pii pair<int, int>

typedef class Pair3 {
	public:
		int x, y, z;
		
		Pair3() {	}
		Pair3(int x, int y, int z) : x(x), y(y), z(z) {	}
} Pair3;

int n, K;
Zi fac[N];
Zi F[Kmx];
int id[Kmx << 1];
boolean vis[Kmx << 1];
vector<pii> H[Kmx << 1];

typedef class Graph {
	public:
		int cnte;
		vector<int> V, X, Y;
		vector<Pair3> Et, En;
		Zi f[S][Kmx], g[Kmx << 1][Kmx][2], h[Kmx];
		vector<Pair3> _G[Kmx << 1], G[Kmx << 1]; // 1: tree edge

		void dfs_build(int p, int c, int fa, vector<pii> *H) {
			if (vis[p]) {
				return;
			}
			:: vis[p] = true;
			if (!c) {
				X.push_back(p);
			} else {
				Y.push_back(p);
			}
			V.push_back(p);
			for (auto& par : H[p]) {
				int e = par.first;
				if (e != fa) {
					_G[p].push_back(Pair3(e, par.second, !:: vis[e]));
				} else {
					_G[p].push_back(Pair3(e, par.second, 1));
				}
				dfs_build(e, c ^ 1, p, H);
			}
		}

		void build(int p, vector<pii> *H) {
			cnte = 0;
			for (int i = 0; i < (K << 1); i++) {
				_G[i].clear(), G[i].clear();
			}
			X.clear(), Y.clear(), V.clear();
			dfs_build(p, 0, -1, ::H);
			sort(V.begin(), V.end());
			memset(id, -1, sizeof(id));
			for (int i = 0; i < (signed) V.size(); i++) {
				id[V[i]] = i;
			}
			Et.clear(), En.clear();
			for (auto& x : X) x = id[x];
			for (auto& y : Y) y = id[y];
			for (int i = 0; i < (K << 1); i++) {
				if (~id[i]) {
					for (auto& par : _G[i]) {
						int x = id[i], y = id[par.x], te = par.z;
						G[x].push_back(Pair3(y, par.y, te));
						if (x < y) {
//							cerr << x << " " << y << " " << par.y << " is tree edge: " << te << '\n';
							cnte++;
							if (te) {
								Et.push_back(Pair3(x, y, par.y));
							} else {
								En.push_back(Pair3(x, y, par.y));
							}
						}
					}
				}
			}
		}

		void work1() {
			int mx = min(cnte, (signed) min(X.size(), Y.size()));
			if (X.size() < Y.size()) {
				int x_sz = X.size();
				pfill(f[0], f[1 << x_sz], Zi(0));
				f[0][0] = 1;
				for (int i = 0, all = 1 << x_sz, x, y, v; i < (signed) Y.size(); i++) {
					y = Y[i];
					for (int s = all - 1; ~s; s--) {
						for (int k = mx; k; k--) {
							for (auto par : G[y]) {
								x = par.x, v = par.y;
								if (!((s >> x) & 1)) {
									f[s | (1 << x)][k] += f[s][k - 1] * v;
								}
							}
						}
					}
				}
				for (int i = 1; i <= mx; i++) {
					Zi &sum = h[i];
					h[i] = 0;
					for (int s = 0, all = 1 << x_sz; s < all; s++) {
						sum += f[s][i];
					}
				}
			} else {
				int x_sz = X.size(), y_sz = Y.size();
				pfill(f[0], f[1 << y_sz], Zi(0));
				f[0][0] = 1;
				for (int i = 0, all = 1 << y_sz, x, y, v; i < (signed) X.size(); i++) {
					x = X[i];
					for (int s = all - 1; ~s; s--) {
						for (int k = mx; k; k--) {
							for (auto par : G[x]) {
								y = par.x - x_sz, v = par.y;
								if (!((s >> y) & 1)) {
									f[s | (1 << y)][k] += f[s][k - 1] * v;
								}
							}
						}
					}
//					Zi sum = 0;
//					for (int s = 0; s < all; s++) {
//						sum += f[s][1];
//					} 
//					cerr << i << ": " << sum.v << '\n';
				}
				for (int i = 1; i <= mx; i++) {
					Zi &sum = h[i];
					h[i] = 0;
					for (int s = 0, all = 1 << y_sz; s < all; s++) {
						sum += f[s][i];
					}
				}
			}
//			for (int i = 0; i <= K; i++) {
//				cerr << h[i].v << '\n';
//			}
			for (int i = K; i; i--) {
				for (int j = 1; j <= mx && j <= i; j++) {
					F[i] += F[i - j] * h[j];
				}
			}
		}

		int sz[Kmx << 1];
		boolean sec[Kmx << 1];
		void dfs(int p, int fa) {
			static Zi tmp[Kmx][2];
			pfill(g[p][0], g[p][Kmx], Zi(0));
			sz[p] = 1;
			if (sec[p]) {
				g[p][0][1] = 1;
			} else {
				g[p][0][0] = 1;
			}
			for (auto& par : G[p]) {
				int e = par.x;
				if (!par.z || e == fa) {
					continue;
				}
				dfs(e, p);
				pfill(tmp[0], tmp[Kmx], Zi(0));
				for (int i = 0; i <= sz[p]; i++) {
					for (int j = 0; j <= sz[e]; j++) {
						tmp[i + j][0] += g[p][i][0] * (g[e][j][0] + g[e][j][1]);
						tmp[i + j][1] += g[p][i][1] * (g[e][j][0] + g[e][j][1]);
						tmp[i + j + 1][1] += g[p][i][0] * g[e][j][0] * par.y;
					}
				}
				sz[p] += sz[e];
				for (int j = 0; j <= sz[p]; j++) {
					g[p][j][0] = tmp[j][0];
					g[p][j][1] = tmp[j][1];
				}
			}
		}

		void work2() {
			int mx = min(cnte, (signed) min(X.size(), Y.size()));
			memset(h, 0, sizeof(h));
			for (int s = 0, all = 1 << En.size(), rt; s < all; s++) {
				memset(sec, false, sizeof(sec));
				boolean aflag = false;
				Zi P = 1;
				int cnt = 0;
				for (int i = 0; i < (signed) En.size(); i++) {
					int x = En[i].x, y = En[i].y;
					if (!((s >> i) & 1)) {
						continue;
					}
					if (sec[x] || sec[y]) {
						aflag = true;
						break;
					}
					P *= En[i].z, cnt += 1;
					sec[x] = sec[y] = true;
				}
				if (aflag) {
					continue;
				}
				dfs(rt = X[0], -1);
				for (int j = 0; j <= mx; j++) {
					h[j + cnt] += (g[rt][j][0] + g[rt][j][1]) * P;
				}
			}
			for (int i = K; i; i--) {
				for (int j = 1; j <= mx && j <= i; j++) {
					F[i] += F[i - j] * h[j];
				}
			}
		}

		void work() {
			if (!cnte) {
				return;
			}
			int x = X.size(), y = Y.size();
			if (cnte - (x + y) + 1 < min(x, y)) {
				work2();
			} else {
				work1();
			}
		}
} Graph;

Graph graph;
int main() {
	scanf("%d%d", &n, &K);
 
	vector<int> X, Y, ex(K + 1), ey(K + 1), v(K + 1);
	for (int i = 1, x, y; i <= K; i++) {
		scanf("%d%d%d", &x, &y, v.data() + i);
		ex[i] = x, ey[i] = y;
		X.push_back(x), Y.push_back(y);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 1; i <= K; i++) {
		ex[i] = lower_bound(X.begin(), X.end(), ex[i]) - X.begin();
		ey[i] = lower_bound(Y.begin(), Y.end(), ey[i]) - Y.begin();
		H[ex[i]].push_back(pii(ey[i] + X.size(), v[i] - 1));
		H[ey[i] + X.size()].push_back(pii(ex[i], v[i] - 1));
//		cerr << ex[i] << " " << ey[i] + X.size() << " " << v[i] - 1 << '\n';
	}
	F[0] = 1;
	for (int i = 0; i < (signed) X.size(); i++) {
		if (!vis[i]) {
			graph.build(i, H);
			graph.work();
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	Zi ans = 0;
	for (int i = 0; i <= (signed) X.size(); i++) {
		ans += F[i] * fac[n - i];
	}
	printf("%d\n", ans.v);
	return 0;
}