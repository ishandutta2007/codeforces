#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int N = 100 * 1000 + 5;

int c[N];
vector <int> adj[N];
map<int, int> mp[N];
int ans[N];
int sz[N];
int par[N];
vector <pair <int, int> > t[N];
vector <int> g[N];

void dfs(int v) {
//	cout << "73 " << v << endl;
	mp[v][c[v]] = 1;
	g[v].push_back(1);
	for (auto u : adj[v]) {
		if (u != par[v]) {
			par[u] = v;
			dfs(u);
			if (g[u].size() > g[v].size()) {
				g[v].swap(g[u]);
				mp[v].swap(mp[u]);
			}
			for (int i = 0; i < g[u].size(); i++) {
				g[v].push_back(0);
			}
			for (auto p : mp[u]) {
				int x = p.first, cnt = p.second;
			//	cout << v << " " << u << " " << x << " " << cnt << endl;
				for (int i = mp[v][x]; i < mp[v][x] + cnt; i++) {
					g[v][i]++;
				}
				mp[v][x] += cnt;
			}
		}
	}
	for (auto p : t[v]) {
		if (g[v].size() >= p.first) {
			ans[p.second] = g[v][p.first - 1];
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < q; i++) {
		int v, k;
		cin >> v >> k;
		t[v].push_back({k, i});
	}
	dfs(1);
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}