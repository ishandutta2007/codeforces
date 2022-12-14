#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 3;
const int maxm = 1e6 + 10;
const int mod = 1e6 + 7;

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

void dfs(int v, int p = -1, int w = 0){
	par[0][v] = p;
	dp[0][v] = w;
	for (int i = 1; i < 20 and par[i - 1][v] != -1; i++){
		par[i][v] = par[i - 1][par[i - 1][v]];
		dp[i][v] = max(dp[i - 1][v], dp[i - 1][par[i - 1][v]]);
	}
	for (auto u : t[v]){
		h[u.first] = h[v] + 1;
		dfs(u.first, v, u.second);
	}
}

int get_par(int v){
	return parent[v] < 0 ? v : parent[v] = get_par(parent[v]);
}

bool merge(int v, int u, int w){
	if ((v = get_par(v)) == (u = get_par(u)))
		return 0;
	parent[v] = u;
	t[u].push_back({v, w});
	return 1;
}

int ans[maxm];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
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
	int root = get_par(1);
	memset(par, -1, sizeof par);
	dfs(root);
	memset(ans, -1, sizeof ans);
	for (int i = 0; i < m; i++){
		if (present[i])
			continue;
		ans[e[i].idx] = lca(e[i].v, e[i].u);
	}
	for (int i = 0; i < m; i++)
		if (ans[i] != -1)
			cout << ans[i] << '\n';
}