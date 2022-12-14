#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 3;
const int maxm = 1e6 + 10;
const int inf = 1e9;

struct edge{
	int v;
	int u;
	int w;
	int idx;
	bool operator < (edge other) const{
		return w < other.w;
	}
};
edge e[maxm];

vector<pair<int, int> > t[maxn];
int parent[maxn];
bool present[maxm];

int par[20][maxn], dp[20][maxn], h[maxn];

int lca(int v, int u){
	if (h[v] < h[u])
		swap(v, u);
	int ret = 0;
	for (int i = 19; i >= 0; i--){
		if (h[v] - (1 << i) >= h[u]){
			ret = max(ret, dp[i][v]);
			v = par[i][v];
		}
	}
	if (v == u)
		return ret;
	for (int i = 19; i >= 0; i--){
		if (par[i][v] != par[i][u]){
			ret = max(ret, max(dp[i][v], dp[i][u]));
			v = par[i][v];
			u = par[i][u];
		}
	}
	return max(ret, max(dp[0][v], dp[0][u]));
}

int up[maxn], sz[maxn], st[maxn], Time = 0, root;

bool CMP(pair<int,int> v, pair<int,int> u){ return sz[v.first] > sz[u.first]; }
	
void DFS(int v){
	st[v] = Time ++;
	sort(t[v].begin(), t[v].end(), CMP);
	for (auto u : t[v]){
		if (v != 1 and u == t[v][0])
			continue;
		if ((v == 1 and u == t[v][0]) or (v != 1 and u == t[v][1]))
			up[u.first] = up[v];
		else
			up[u.first] = u.first;
		DFS(u.first);
	}
}

void dfs(int v, int p = -1, int w = 0){
	par[0][v] = p;
	dp[0][v] = w;
	for (int i = 1; i < 20 and par[i - 1][v] != -1; i++){
		par[i][v] = par[i - 1][par[i - 1][v]];
		dp[i][v] = max(dp[i - 1][v], dp[i - 1][par[i - 1][v]]);
	}
	sz[v] = 1;
	for (auto u : t[v]){
		if (u.first == p)
			continue;
		h[u.first] = h[v] + 1;
		dfs(u.first, v, u.second);
		sz[v] += sz[u.first];
	}
}

int get_par(int v){
	return parent[v] < 0 ? v : parent[v] = get_par(parent[v]);
}

bool merge(int v, int u, int w){
	if (get_par(v) == get_par(u))
		return 0;
	parent[get_par(v)] = get_par(u);
	t[u].push_back({v, w});
	t[v].push_back({u, w});
	return 1;
}

int seg[4 * maxn];

int get(int id, int L, int R, int idx){
	if (idx < L or R <= idx)
		return inf;
	if (L + 1 == R)
		return seg[id];
	int mid = (L + R) >> 1;
	return min(seg[id], min(get(2 * id + 0, L, mid, idx), get(2 * id + 1, mid, R, idx)));
}

void add(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id] = min(seg[id], val);
		return;
	}
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, val);
	add(2 * id + 1, mid, R, l, r, val);
}

int n;
void change(int v, int u, int w){
	while (up[v] != up[u]){
		if (h[up[v]] < h[up[u]])
			swap(v, u);
		int T = up[v];
		add(1, 0, n, st[T], st[v] + 1, w);
		v = par[0][up[v]];
	}
	if (v == u)
		return;
	if (h[v] < h[u])
		swap(v, u);
	add(1, 0, n, st[u] + 1, st[v] + 1, w);
}

int ans[maxm];
int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> e[i].v >> e[i].u >> e[i].w;
		e[i].idx = i;
	}
	sort(e, e + m);
	memset(parent, -1, sizeof parent);
	for (int i = 0; i < m; i++)
		if (merge(e[i].v, e[i].u, e[i].w))
			present[i] = 1;
	root = 1;
	memset(par, -1, sizeof par);
	dfs(root);
	for (int i = 0; i < m; i++){
		if (present[i])
			continue;
		ans[e[i].idx] = lca(e[i].v, e[i].u);
	}
	up[root] = root;
	DFS(root);
	// build
	for (int i = 0; i < 4 * maxn; i++)
		seg[i] = inf;
	for (int i = 0; i < m; i++){
		if (present[i])
			continue;
		change(e[i].v, e[i].u, e[i].w);
	}
	for (int i = 0; i < m; i++){
		if (!present[i])
			continue;
		if (h[e[i].v] < h[e[i].u])
			swap(e[i].v, e[i].u);
		ans[e[i].idx] = get(1, 0, n, st[e[i].v]);
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << '\n';
}