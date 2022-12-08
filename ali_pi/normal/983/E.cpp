#include<bits/stdc++.h>

using namespace :: std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define up asfdklj
#define tm klajsdfoi

const int MAXN = 2e5 + 10;
const int LOG = 18;
const int INF = 1e8;

int n, m, q;
vector<int> adj[MAXN], vec[MAXN];
vector<pii> sec[MAXN];
int par[LOG][MAXN], depth[MAXN], up[LOG][MAXN], ans[MAXN];
int st[MAXN], ft[MAXN], tm;

void plant(int v, int de = 0){
	st[v] = tm++;
	depth[v] = de;
	for (int u:adj[v])
		plant(u, de + 1);
	ft[v] = tm;
}

void preLCA(){
	for (int w = 1; w < LOG; w++)
		for (int v = 0; v < n; v++)
			if (~par[w-1][v])
				par[w][v] = par[w-1][par[w-1][v]];
			else
				par[w][v] = -1;
}

int lca(int u, int v){
	if (depth[u] < depth[v]) swap(u, v);
	for (int w = LOG-1; ~w; w--)
		if (depth[u] - (1<<w) >= depth[v])
			u = par[w][u];
	if (u == v) return v;
	for (int w = LOG-1; ~w; w--)
		if (par[w][v] != par[w][u])
			v = par[w][v], u = par[w][u];
	return par[0][v];
}

void updUp(int v, int p){
	if (up[0][v] == -1 || depth[up[0][v]] > depth[p])
		up[0][v] = p;
}

int getAns(int v, int p){
	if (v == p) return 0;
	int ret = 0;
	for (int w = LOG-1; ~w; w--)
		if (up[w][v] != -1 && depth[up[w][v]] > depth[p])
			v = up[w][v], ret += 1<<w;
	if (up[0][v] != -1)
		return ret + 1;
	return INF;
}

int goUp(int v, int x){
	for (int w = LOG-1; ~w; w--)
		if (x >= (1<<w))
			v = up[w][v], x -= 1<<w;
	return v;
}

set<int> ss[MAXN];
void go(int v){
	int mx = -1;
	for (int u:adj[v]) go(u), mx = max(mx, (int)ss[u].size());
	if (mx != -1) {
		for (int u:adj[v])
			if (ss[u].size() == mx) {
				ss[v].swap(ss[u]);
				break;
			}
	}
	for (int u:vec[v])
		ss[v].insert(st[u]);
	for (int u:adj[v]) {
		for (int x:ss[u])
			ss[v].insert(x);
		ss[u].clear();
	}
	for (auto x:sec[v]){
		int id = x.F, u = x.S;
		auto it = ss[v].lower_bound(st[u]);
		if (it != ss[v].end() && *it < ft[u])
			ans[id]--;
	}
}

void dfs(int v){
	for (int u:adj[v]) {
		dfs(u);
		if (up[0][v] == -1 || (up[0][u] != -1 && depth[up[0][v]] > depth[up[0][u]]))
			up[0][v] = up[0][u];
	}
	if (up[0][v] != -1 && depth[up[0][v]] >= depth[v])
		up[0][v] = -1;
}

int main(){
	cin >> n;
	par[0][0] = -1;
	for (int i = 1; i < n; i++){
		int p; cin >> p, p--;
		adj[p].push_back(i);
		par[0][i] = p;
	}
	plant(0);
	preLCA();
	cin >> m;
	memset(up, -1, sizeof(up));
	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b, a--, b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
		int p = lca(a, b);
		updUp(a, p);
		updUp(b, p);
	}
	dfs(0);
	for (int w = 1; w < LOG; w++)
		for (int v = 0; v < n; v++)
			if (~up[w-1][v])
				up[w][v] = up[w-1][up[w-1][v]];
			else
				up[w][v] = -1;
	cin >> q;
	memset(ans, 63, sizeof(ans));
	for (int i = 0; i < q; i++){
		int u, v; cin >> u >> v, u--, v--;
		int p = lca(u, v);
		int t1 = getAns(u, p), t2 = getAns(v, p);
		ans[i] = t1 + t2;
		if (ans[i] < INF && u != p && v != p){
			u = goUp(u, t1-1);
			v = goUp(v, t2-1);
			sec[u].push_back({i, v});
		}
	}
	go(0);
	for (int i = 0; i < q; i++) {
		if (ans[i] > 1e7)
			ans[i] = -1;
		cout << ans[i] << "\n";
	}
}