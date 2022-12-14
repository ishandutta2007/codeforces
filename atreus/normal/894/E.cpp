#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;

int n, cnt = 0, cmp[maxn];
bool visited[maxn];
vector<pair<int, int> > g[maxn][2], in[maxn];
vector<int> topol;
ll sum[maxn], par[maxn];

ll get_cost(int x){
	int lo = 0, hi = min(100000, x + 1);
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (x >= sum[mid])
			lo = mid;
		else
			hi = mid;
	}
	return 1ll * hi * x - par[lo];
}

void DFS(int v){
	visited[v] = 1;
	for (auto u : g[v][1])
		if (!visited[u.first])
			DFS(u.first);
	cmp[v] = cnt;
}

void dfs(int v){
	visited[v] = 1;
	for (auto u : g[v][0])
		if (!visited[u.first])
			dfs(u.first);
	topol.push_back(v);
}

ll cost[maxn], dp[maxn];

void scc(){
	for (int v = 0; v < n; v++)
		if (!visited[v])
			dfs(v);
	memset(visited, 0, sizeof visited);
	reverse(topol.begin(), topol.end());
	for (auto v : topol){
		if (!visited[v]){
			DFS(v);
			cnt ++;
		}
	}
	for (int v = 0; v < n; v++){
		for (auto u : g[v][0]){
			if (cmp[v] == cmp[u.first])
				cost[cmp[v]] += get_cost(u.second);
			else
				in[cmp[u.first]].push_back({cmp[v], u.second});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 100000; i++){
		sum[i] = sum[i - 1] + i;
		par[i] = par[i - 1] + sum[i];
	}
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		v --, u --;
		g[v][0].push_back({u, w});
		g[u][1].push_back({v, w});
	}
	scc();
	int s;
	cin >> s;
	s --;
	memset(dp, -63, sizeof dp);
	dp[cmp[s]] = cost[cmp[s]];
	ll answer = dp[cmp[s]];
	for (int v = 0; v < cnt; v++){
		for (auto u : in[v]){
			dp[v] = max(dp[v], dp[u.first] + u.second + cost[v]);
			answer = max(answer, dp[v]);
		}
	}
	cout << answer << endl;
}