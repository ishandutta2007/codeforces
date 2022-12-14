#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;

int n, k, cnt, h[maxn], par[maxn][22];
bool visited[maxn], a[maxn];
vector<int> g[maxn][2], t[maxn], topol, in[maxn];

int cost[maxn], dp[maxn], cmp[maxn];

void dfs(int v, bool w){
	visited[v] = 1;
	if (w == 1){
		cmp[v] = cnt;
		cost[cnt] += a[v];
	}
	for (auto u : g[v][w]){
		if (!visited[u]){
			dfs(u, w);
		}
	}
	if (w == 0)
		topol.push_back(v);
}

int scc(){
	for (int v = 0; v < n; v++)
		if (!visited[v])
			dfs(v, 0);
	memset(visited, 0, sizeof visited);
	reverse(topol.begin(), topol.end());
	for (auto v : topol){
		if (!visited[v]){
			dfs(v, 1);
			cnt ++;
		}
	}
	for (int v = 0; v < n; v++)
		for (auto u : g[v][0])
			if (cmp[v] != cmp[u])
				in[cmp[u]].push_back(cmp[v]);
	dp[0] = cost[0];
	int answer = dp[0];
	for (int c = 1; c < cnt; c++){
		for (auto other : in[c]){
			dp[c] = max(dp[c], dp[other] + cost[c]);
		}
		answer = max(answer, dp[c]);
	}
	return answer;
}

int get_par(int v, int h){
	for (int i = 20; i >= 0; i--)
		if (h & (1 << i))
			v = par[v][i];
	return v;
}

void dfs_on_tree(int v, int parent = -1){
	par[v][0] = parent;
	for (int i = 1; i <= 20 and par[v][i - 1] != -1; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	for (auto u : t[v]){
		h[u] = h[v] + 1;
		g[v][0].push_back(u);
		g[u][1].push_back(v);
		dfs_on_tree(u, v);
	}
	if (t[v].size() == 0){
		a[v] = 1;
		int sz = min(h[v], k);
		int u = get_par(v, sz);
		g[v][0].push_back(u);
		g[u][1].push_back(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	cin >> n >> k;
	for (int v = 1; v < n; v++){
		int p;
		cin >> p;
		p --;
		t[p].push_back(v);
	}
	dfs_on_tree(0);
	cout << scc() << '\n';
}