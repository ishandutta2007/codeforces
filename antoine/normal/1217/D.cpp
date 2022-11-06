#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 5009;
vector<int> adj[MxN + 9];
int color[MxN + 9];

bool dfs(const int u) {
	color[u] = 1;

	for (int v : adj[u])
		if (!color[v]) {
			if (dfs(v))
				return true;
		} else if (color[v] == 1)
			return true;
	color[u] = 2;
	return false;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	for (pair<int, int> &p : edges) {
		cin >> p.first >> p.second;
		adj[p.first].push_back(p.second);
	}
	for (int i = 1; i <= n; ++i)
		if (!color[i] && dfs(i)) {
			cout << "2\n";
			for(int i = 0; i < m; ++i)
				cout << 1  +(edges[i].first < edges[i].second) << ' ';
			return 0;
		}
	cout << "1\n";
	for (int i = 0; i < m; ++i)
		cout << "1 ";
	return 0;
}