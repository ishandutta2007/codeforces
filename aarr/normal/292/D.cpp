#include <iostream>
#include <vector>
using namespace std;

const int N = 505;
int l, r, nparts;

vector <pair <int, int> > adj[N];
bool mark[N];
void dfs(int v) {
	mark[v] = true;
	for (auto p : adj[v]) {
	//	int u = adj[v][i].first, x = adj[v][i].second;
		if (!(l <= p.second && p.second <= r) && !mark[p.first])
			dfs(p.first);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> l;
		cin >> r;
		nparts = 0;
		for (int j = 1; j <= n; j++) {
			if (!mark[j]) {
				dfs(j);
				nparts++;
			}
		}
		for (int j = 1; j <= n; j++) {
			mark[j] = false;
		}
		cout << nparts << "\n";
	}
	return 0;
}