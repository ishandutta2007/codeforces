#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Mx = (int) 2e5 + 9;
vector<int> adj[Mx + 9];
bool vis[Mx + 9];

void dfs(const int u) {
	vis[u] = true;

	for (const int &v : adj[u])
		if (!vis[v]) {
			cout << u << ' ' << v << '\n';
			dfs(v);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int u = 0;
	for (int i = 1; i <= n; ++i)
		if (adj[i].size() > adj[u].size())
			u = i;

	vis[u] = true;
	for (int v : adj[u]) {
		cout << u << ' ' << v << '\n';
		vis[v] = true;
	}
	for (int v : adj[u])
		dfs(v);
	return 0;
}