#include <bits/stdc++.h>
using namespace std;
const int K = 18;
const int N = 4e5 + 5;
int n, m, dn;
int val[N], ans[N], sz[N];
int node, fa[N], ls[N], rs[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
struct edge {
	int u, v, w, id;
	bool operator < (const edge &r) const {return w < r.w;}
} e[N];
struct Tree {
	int dep[N], mx[K][N], fa[K][N];
	vector <pair <int, int>> e[N];
	void init() {for(int i = 1; i <= n; i++) e[i].clear();}
	void add(int u, int v, int w) {
		// cerr << "add " << u << " " << v << " " << w << endl;
		e[u].push_back(make_pair(v, w)), e[v].push_back(make_pair(u, w));
	}
	void dfs(int id, int f) {
		// cerr << "dfs " << id << " " << f << endl;
		fa[0][id] = f, dep[id] = dep[f] + 1;
		for(auto it : e[id]) {
			int to = it.first;
			if(to == f) continue;
			mx[0][to] = it.second, dfs(to, id);
			// cerr << "mx " << to << " " << mx[0][to] << endl;
		}
	}
	int dist(int u, int v) {
		int ans = 0;
		if(dep[u] < dep[v]) swap(u, v);
		for(int i = 17; ~i; i--) if(dep[fa[i][u]] >= dep[v]) ans = max(ans, mx[i][u]), u = fa[i][u];
		if(u == v) return ans;
		for(int i = 17; ~i; i--)
			if(fa[i][u] != fa[i][v])
				ans = max(ans, max(mx[i][u], mx[i][v])), u = fa[i][u], v = fa[i][v];
		return max(ans, max(mx[0][u], mx[0][v]));
	}
	void build() {
		dfs(1, 0);
		for(int i = 1; i <= 17; i++)
			for(int j = 1; j <= n; j++) {
				fa[i][j] = fa[i - 1][fa[i - 1][j]];
				mx[i][j] = max(mx[i - 1][j], mx[i - 1][fa[i - 1][j]]);
			}
	}
} tr;
set <int> g[N], s[N], ind[N];
void merge(set <int> &x, set <int> &y, int w) {
	// cerr << "add edge " << *x.begin() << " " << *y.begin() << " " << w << endl;
	tr.add(*x.begin(), *y.begin(), w);
	if(x.size() < y.size()) swap(x, y);
	for(int it : y) x.insert(it);
	y.clear();
}
void calc(int id) {
	if(id <= n) return s[id].insert(id), sz[id] = 1, void();
	int u = ls[id], v = rs[id];
	calc(u), calc(v), sz[id] = sz[u] + sz[v];
	if(sz[u] > sz[v]) swap(u, v);
	for(int it : s[u]) {
		set <int> tmp = ind[it];
		for(int x : tmp) {
			set <int> tmp2 = s[v];
			for(int y : tmp2) {
				bool found = 0;
				for(int z : ind[y]) if(g[x].find(z) == g[x].end()) {found = 1; break;}
				if(found) merge(ind[it], ind[y], val[id]), s[v].erase(y);
			}
		}
		s[v].insert(it);
	}
	swap(s[id], s[v]);
}
void solve() {
	cin >> n >> m;
	dn = 0, node = n, tr.init(); // init
	// for(int i = 1; i <= n; i++) assert(g[i].empty());
	for(int i = 1; i <= n; i++) ind[i].clear(), ind[i].insert(i);
	for(int i = 1; i <= n << 1; i++) fa[i] = i, g[i].clear(), s[i].clear();
	for(int i = 1; i <= m; i++) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w), e[i].id = i;
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= m; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if(u == v) continue;
		val[++node] = e[i].w, fa[u] = fa[v] = node;
		ls[node] = u, rs[node] = v;
		// cerr << node << " " << u << " " << v << endl;
	}
	for(int i = 1; i <= m; i++) g[e[i].u].insert(e[i].v), g[e[i].v].insert(e[i].u);
	calc(node);
	tr.build(); // ADD THIS LINE =.=
	for(int i = 1; i <= m; i++) ans[e[i].id] = tr.dist(e[i].u, e[i].v);
	for(int i = 1; i <= m; i++) printf("%d ", ans[i]);
	cout << endl;
}
int main() {
	// freopen("1.in", "r", stdin);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}

/*
2022/5/2
start thinking at 9:35

 MST.
 S, T , S  T  v .
 MST.
.

 2, 3 .
, .
.
 set.
 set , ,  set .
kruskal .

.

start coding at 10:20
finish debugging at 11:59
*/