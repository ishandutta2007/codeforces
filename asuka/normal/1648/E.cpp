#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")

const int N = 200015;

int fa[N << 1];
void init(int n) {rep(i, 1, n) fa[i] = i;}
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

int n, m, val[N << 1], ans[N];

vector<int> e[N << 1], s[N];

vector<pii> g[N];

map<int, bool> M[N];

void merge(vector<int> &a, vector<int> &b) {
	if (SZ(a) < SZ(b)) swap(a, b);

	for (int x : b) a.pb(x);
}

void merge(set<int> &a, set<int> &b) {
	if (SZ(a) < SZ(b)) swap(a, b);

	for (int x : b) a.insert(x);
}

// void out() {
// 	rep(i, 1, n) {
// 		if (i != find(i)) continue;

// 		printf("RT: %d\n", i);

// 		for (int x : s[i]) printf("%d ", x);

// 		printf("\n");
// 	}
// }

set<int> dfs(int u) {

	if (u <= n) return (set<int>) {u};

	set<int> f;

	int w = val[u];

	// printf("IN %d\n", u);

	// out();

	for (int v : e[u]) {
		auto g = dfs(v);

		if (SZ(f) == 0) {
			f = g;
			continue;
		}

		vector<pii> eed;

		// printf("merge subtree\n");

		// for (int x : f) {
		// 	printf("X %d :", x);
		// 	printf("{ ");

		// 	for (int xx : s[x]) printf("%d ", xx);

		// 	printf("} ");
		// }

		// printf("\n");

		// for (int x : g) {
		// 	printf("X %d :", x);
		// 	printf("{ ");

		// 	for (int xx : s[x]) printf("%d ", xx);

		// 	printf("} ");
		// }

		// printf("\n");

		for (int x : f) {
			vector<int> ed;

			for (int y : g) {
				bool flag = 0;

				for (int p : s[x]) {
					if (flag) break;

					for (int q : s[y]) {
						if (M[p][q]) {
							continue;
							// fprintf(stderr, "%d %d\n", p, q);

						} else {
							flag = 1;
							// printf("add %d %d %d\n", p, q, w);
							::g[p].emplace_back(q, w);
							::g[q].emplace_back(p, w);
							break;
						}
					}
				}

				if (!flag) continue;

				ed.pb(y);
			}

			rep(i, 1, SZ(ed) - 1) {
				int x = ed[i], y = ed[i - 1];

				// assert(find(x) == x && find(y) == y);
				// assert(x != y);

				// printf("merge1 %d %d %d %d\n", x, find(x), y, find(y));
				fa[y] = x;
				merge(s[x], s[y]);
				// printf("erase1 %d\n", y);
				g.erase(y);
			}

			if (SZ(ed)) eed.emplace_back(x, ed.back());
		}

		merge(f, g);

		for (auto [x, y] : eed) {
			int fx = find(x), fy = find(y);

			if (fx == fy) continue;

			if (f.find(fy) == f.end()) swap(fx, fy);

			// assert(f.find(fy) != f.end());

			// printf("merge %d %d\n", fx, fy);
			fa[fy] = fx;
			merge(s[fx], s[fy]);
			// printf("erase %d\n", fy);
			f.erase(fy);
		}

		// out();
	}

	return f;
}

int up[N][18], Max[N][18], dep[N];

void dfs2(int u, int pa) {
	up[u][0] = pa; dep[u] = dep[pa] + 1;
	// printf("(%d %d)\n", u, pa);
	rep(j, 1, 17) up[u][j] = up[up[u][j - 1]][j - 1], Max[u][j] = max(Max[u][j - 1], Max[up[u][j - 1]][j - 1]);

	for (auto [v, w] : g[u]) {
		if (v == pa) continue;

		Max[v][0] = w;
		dfs2(v, u);
	}
}

int ask(int u, int v) {
	// cerr << "u v "  << u << ' ' << v << endl;

	if (dep[u] < dep[v]) swap(u, v);

	int res = 0, t = dep[u] - dep[v];

	// printf("ASK %d %d ", u, v);

	rep(j, 0, 17) if (t >> j & 1) {
		res = max(res, Max[u][j]);
		u = up[u][j];
		// printf("UP %d %d\n", u, j);
	}

	// printf("JUMP %d %d\n", u, v);

	if (u == v) return res;

	per(j, 0, 17) {
		if (up[u][j] != up[v][j]) {
			res = max({res, Max[u][j], Max[v][j]});
			u = up[u][j]; v = up[v][j];
		}
	}
	// printf("%d\n", max(res, Max[u][0]));
	return max({res, Max[u][0], Max[v][0]});
}

void solve() {
	scanf("%d%d", &n, &m);
	vector<tuple<int, int, int, int>> ed;
	rep(i, 1, n << 1) e[i].clear();
	rep(i, 1, n) M[i].clear(), g[i].clear(), s[i] = (vector<int>) {i};
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ed.emplace_back(w, u, v, i);
		M[u][v] = M[v][u] = 1;

	}
	sort(all(ed));
	int tot = n;
	init(n + n);

	for (auto [w, u, v, i] : ed) {
		int fu = find(u), fv = find(v);

		if (fu == fv) continue;

		tot++; fa[fu] = fa[fv] = tot;
		e[tot].pb(fu); e[tot].pb(fv);
		// printf("(%d %d %d)\n", tot, fu, fv);
		val[tot] = w;
	}

	// cerr << "ok" << endl;
	init(n);
	dfs(tot);
	// cerr << "ok" << endl;
	dfs2(1, 0);
	// cerr << "ok" << endl;

	for (auto [w, u, v, i] : ed) ans[i] = ask(u, v);

	rep(i, 1, m) printf("%d ", ans[i]);
	printf("\n");
}

int T;

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	for (scanf("%d", &T); T; T--) solve();

	return 0;
}