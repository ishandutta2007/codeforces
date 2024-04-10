#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 4e5 + 10;

vector<int> T[maxn];
int cit[maxn], dp[maxn], sz[maxn], s[maxn];

int Time, st[maxn], ft[maxn], h[maxn], par[maxn][19];
int lca(int v, int u){
	if (h[v] < h[u])
		swap(v, u);
	for (int i = 18; i >= 0; i--)
		if (h[v] - (1 << i) >= h[u])
			v = par[v][i];
	if (v == u)
		return v;
	for (int i = 18; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int dis(int v, int u){
	return h[v] + h[u] - 2 * h[lca(v, u)];
}

pair<int,int> timereach(int t, int v){
	int u = cit[t - 1];
	int Dis = dis(v, u);
	return {(Dis+s[t-1]-1)/s[t-1], t-1};
}

void dfsdw(int v, int par = -1){
	for (auto u : T[v]){
		if (u == par)
			continue;
		if (dp[u] == 0 or timereach(dp[v], u) <= timereach(dp[u], u))
			dp[u] = dp[v];
		dfsdw(u, v);
	}
}

void dfsup(int v, int par = -1){
	for (auto u : T[v]){
		if (u == par)
			continue;
		dfsup(u, v);
		if (dp[u] == 0)
			continue;
		if (dp[v] == 0 or timereach(dp[u], v) <= timereach(dp[v], v))
			dp[v] = dp[u];
	}
}

vector<int> t[maxn];

void dfs(int v, int p = -1){
	par[v][0] = p;
	for (int i = 1; par[v][i - 1] != -1 and i < 19; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	st[v] = Time ++;
	for (auto u : t[v])
		if (u != p)
			h[u] = h[v] + 1, dfs(u, v);
	ft[v] = Time;
}

int imp[maxn], parent[maxn];
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	memset(par, -1, sizeof par);
	dfs(1);
	int q;
	cin >> q;
	while (q --){
		int k, m;
		cin >> k >> m;
		vector<int> sqz;
		for (int i = 0; i < k; i++){
			cin >> cit[i] >> s[i];
			sqz.push_back(cit[i]);
			dp[cit[i]] = i + 1;
		}
		for (int i = 0; i < m; i++){
			cin >> imp[i];
			sqz.push_back(imp[i]);
		}
		sort(sqz.begin(), sqz.end(), [](int v, int u){ return st[v] < st[u]; });
		int sz = sqz.size();
		for (int i = 0; i < sz - 1; i++)
			sqz.push_back(lca(sqz[i], sqz[i+1]));
		sort(sqz.begin(), sqz.end(), [](int v, int u){ return st[v] < st[u]; });
		sqz.resize(unique(sqz.begin(), sqz.end()) - sqz.begin());
		int root = *sqz.begin();

		for (int i = 1; i < (int)sqz.size(); i++){
			int v = sqz[i];
			parent[v] = sqz[i - 1];
			while (lca(v, parent[v]) != parent[v])
				parent[v] = parent[parent[v]];
			T[parent[v]].push_back(v);
			T[v].push_back(parent[v]);
		}
		dfsup(root);
		dfsdw(root);
		for (int i = 0; i < m; i++)
			cout << dp[imp[i]] << " \n"[i == m - 1];
		for (int i = 0; i < (int)sqz.size(); i++){
			T[sqz[i]].clear();
			dp[sqz[i]] = 0;
		}
	}
}