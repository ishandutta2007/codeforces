#include<bits/stdc++.h>

using namespace std;

int n, m;
bool vis[200005];
int check[200005];
int res[200005];
pair<int, int> ii[200005];
vector<pair<int, int>> adj[200005];
bool flag = 0;

void dfs(int u, int c, int t) {
	vis[u] = true;
	for (auto v : adj[u]) {
		if (v.first == t) continue;
		if (check[v.second] == 3 - c) flag = 1;
		check[v.second] = 3 - c;
		if (ii[v.second].first == v.first) res[v.second] = 3 - c;
		else res[v.second] = c; 
		if (!vis[v.first]) {
			dfs(v.first, 3 - c, u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		ii[i] = make_pair(u, v);
		adj[u].push_back(make_pair(v, i));
		adj[v].push_back(make_pair(u, i));
	}
	dfs(1, 1, 0);
	if (flag) return cout << "NO", 0;
	cout << "YES" << endl;
	for (int i = 1; i <= m; i++) {
		cout << res[i] % 2;
	}
	return 0;
}