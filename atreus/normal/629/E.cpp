#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;

int par[maxn][22], h[maxn];
vector <int> t[maxn];

int st[maxn], ft[maxn];

ll dp_sub[maxn], dp_up[maxn];
int sz_sub[maxn];

int Time = 0;
void dfs(int v, int p = -1){
	par[v][0] = p;
	for (int i = 1; i <= 20 and par[v][i - 1] != -1; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	sz_sub[v] = 1;

	st[v] = Time ++;
	for (auto u : t[v]){
		if (u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
			sz_sub[v] += sz_sub[u];
			dp_sub[v] += dp_sub[u] + sz_sub[u];
		}
	}
	ft[v] = Time;
}

int n;

void dfs2(int v){
	for (auto u : t[v]){
		if (u != par[v][0]){
			dp_up[u] = (dp_up[v] + dp_sub[v] - dp_sub[u] - sz_sub[u]) + n - sz_sub[u];
			dfs2(u);
		}
	}
}

int get_par(int v, int up){
	for (int i = 20; i >= 0; i--)
		if (up & (1 << i))
			v = par[v][i];
	return v;
}

int lca(int v, int u){
	if (h[v] > h[u])
		swap(v, u);
	u = get_par(u, h[u] - h[v]);
	if (u == v)
		return v;
	for (int i = 20; i >= 0; i--){
		if (par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}

int dis(int v, int u){
	return h[v] + h[u] - 2 * h[lca(v, u)];
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	dfs2(1);
	for (int i = 1; i <= m; i++){
		int v, u;
		cin >> v >> u;
		if (st[v] > st[u])
			swap(v, u);
		ll sigma1, sigma2, sz1, sz2;
		if (ft[v] >= ft[u]){
			int w = get_par(u, h[u] - h[v] - 1);
			sigma1 = dp_sub[v] - (dp_sub[w] + sz_sub[w]) + dp_up[v];
			sigma2 = dp_sub[u];
			sz1 = n - sz_sub[w];
			sz2 = sz_sub[u];
		}
		else{
			sigma1 = dp_sub[v];
			sigma2 = dp_sub[u];
			sz1 = sz_sub[v];
			sz2 = sz_sub[u];
		}
		cout << fixed << setprecision(6) << 1. * (sigma1 * sz2 + sigma2 * sz1) / (sz1 * sz2) + dis(v, u) + 1 << '\n';
	}
}