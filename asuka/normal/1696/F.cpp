#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 105;
struct solver {
	int n;
	char s[N];
	set<vector<int>> S[N];
	vector<pii> v[N], ans;
	vector<tuple<int, int, int, int>> xz;
	vector<int> e[N], g[N];
	bool vis[N];

	void add(int u, int v) {
		ans.eb(u, v);
		g[u].pb(v), g[v].pb(u);
	}

	void dfs(int u, vector<int>& vec) {
		vis[u] = 1;
		vec.pb(u);

		for (int v : e[u]) {
			if (!vis[v]) dfs(v, vec);
		}
	}

	int dis[N][N];

	void dfs(int u, int pa, int d[]) {
		for (int v : g[u]) {
			if (v == pa) continue;

			d[v] = d[u] + 1;
			dfs(v, u, d);
		}
	}

	void check() {
		memset(dis, 0, sizeof dis);

		rep(i, 1, n) dfs(i, 0, dis[i]);

		for (auto [u, v, z, o] : xz) {
			if ((dis[u][z] == dis[v][z]) != o) {
				puts("No");
				return;
			}
		}

		puts("Yes");

		for (auto [u, v] : ans) {
			printf("%d %d\n", u, v);
		}

		return;
	}

	bool Gao(int u, int v) {
		for (auto vec : S[v]) {
			vector<int> nvec = vec;

			if (count(all(nvec), u) > 0) {
				nvec.erase(find(all(nvec), u));
			}

			if (S[u].count(nvec) == 0) return 0;
		}

		return 1;
	}

	void solve() {
		scanf("%d", &n);
		bool fl = 1;

		rep(i, 1, n) {
			rep(j, 1, n - i) {
				scanf("%s", s + 1);

				rep(k, 1, n) {
					if (s[k] == '1') {
						v[k].eb(i, i + j);

						if (i == k || i + j == k) {
							fl = 0;
						}
					}

					xz.eb(i, i + j, k, s[k] - '0');
				}
			}
		}

		if (!fl) {
			puts("No");
			return;
		}

		rep(i, 1, n) {
			rep(j, 1, n) e[j].clear();

			for (auto [u, v] : v[i]) e[u].pb(v), e[v].pb(u);

			rep(j, 1, n) vis[j] = 0;

			rep(j, 1, n) {
				if (i == j) continue;

				if (!vis[j]) {
					vector<int> vec;
					dfs(j, vec);
					S[i].insert(vec);
				}
			}
		}

		vector<int> rem(n);
		iota(all(rem), 1);

		auto Del = [&](int x) {
			rem.erase(find(all(rem), x));

			for (int y : rem) {
				for (auto it = S[y].begin(); it != S[y].end(); ++it) {
					if (count(all((*it)), x) > 0) {
						auto vec = *it;
						S[y].erase(it);
						vec.erase(find(all(vec), x));

						if (SZ(vec) > 0) S[y].insert(vec);

						break;
					}
				}
			}
		};

		while (1) {
			if (SZ(rem) == 2) {
				add(rem[0], rem[1]);
				check();
				return;
			}

			int FL = 0;

			for (int x : rem) {
				for (auto vec : S[x]) {
					if (SZ(vec) != 1) continue;

					if (Gao(x, vec[0])) {
						add(x, vec[0]);
						FL = x;
						break;
					}
				}

				if (FL) break;
			}

			if (FL) Del(FL);
			else {
				puts("No");
				return;
			}
		}
	}
};

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);

	while (T--) {
		auto ptr = make_unique<solver>();
		ptr -> solve();
	}

	return 0;
}