#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
vector<int> adj[MxN + 9];
int sz[MxN + 9];

ll sum = 0;

void dfs(const int u, vector<int> &nodes) {
	nodes.push_back(u);
	for (int v : adj[u]) {
		adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
		dfs(v, nodes);
		nodes.push_back(u);
		sz[u] += sz[v];
	}
	sum += ++sz[u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> nodes;
	dfs(1, nodes);
	ll ans = sum;
	for (int i = 0; i + 1 < (int) nodes.size(); ++i) {
		sum -= sz[nodes[i + 1]];
		sz[nodes[i]] = n - sz[nodes[i + 1]];
		sz[nodes[i + 1]] = n;
		sum += sz[nodes[i]];
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}