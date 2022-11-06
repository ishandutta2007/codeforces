#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MxN = (int) 2e5 + 9;
pair<int, int> edges[MxN + 9];
vector<int> adj[MxN + 9];
int color[MxN + 9];
bool vis[MxN + 9];

void dfs(const int u) {
	vis[u] = true;
	for (const int &v : adj[u]) {
		if (vis[v]) {
			if (color[v] == color[u]) {
				cout << "NO";
				exit(0);
			}
		} else {
			color[v] = !color[u];
			dfs(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int &u = edges[i].first;
		int &v = edges[i].second;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	cout << "YES\n";

	for(int i = 0; i < m; ++i)
		cout << color[edges[i].first];
	return 0;
}