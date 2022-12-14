#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

vector<pair<int, int> > g[maxn];
ll a[2], c[maxn], val[maxn];
bool visited[maxn], h[maxn];
pair<int, int> Edge[maxn];

void dfs(int v){
	a[h[v]] += c[v];
	visited[v] = 1;
	for (auto edge : g[v]){
		int u = edge.first;
		if (!visited[u]){
			h[u] = h[v] ^ 1;
			dfs(u);
		}
	}
}

void DFS(int v, int par = -1, int paridx = -1){
	visited[v] = 1;
	for (auto edge : g[v]){
		int u = edge.first, idx = edge.second;
		if (!visited[u])
			DFS(u, v, idx);
	}
	if (paridx != -1){
		val[paridx] = c[v];
		c[par] -= c[v];
		c[v] -= 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int v = 1; v <= n; v++)
		cin >> c[v];
	for (int i = 1; i <= m; i++){
		int v, u;
		cin >> v >> u;
		g[v].push_back({u, i});
		g[u].push_back({v, i});
		Edge[i] = {v, u};
	}
	dfs(1);
	for (int i = 1; i <= m; i++){
		int v = Edge[i].first, u = Edge[i].second;
		if (h[v] != h[u])
			continue;
		ll diff = (a[h[v]] - a[(h[v]^1)]) / 2;
		c[v] -= diff;
		c[u] -= diff;
		a[h[v]] -= 2 * diff;
		val[i] = diff;
	}
	if (a[0] != a[1])
		return cout << "NO\n", 0;
	memset(visited, 0, sizeof visited);
	DFS(1);
	cout << "YES\n";
	for (int i = 1; i <= m; i++)
		cout << val[i] << '\n';
}