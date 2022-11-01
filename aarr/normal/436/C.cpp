#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int K = 1005, N = 15;

int par[K];
int dis[K];
bool mark[K];
char c[K][N][N];
set <pair <int, int> > s;
vector <pair <int, int> > vec;
vector <pair <int, int> > adj[K];

int main() {
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	for (int v = 1; v <= k; v++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> c[v][i][j];
			}
		}
	}
	for (int v = 1; v <= k; v++) {
		for (int u = 1; u <= k; u++) {
			int sm = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (c[v][i][j] != c[u][i][j]) {
						sm += w;
					}
				}
			}
			sm = min(sm, n * m);
			adj[v].push_back({u, sm});
		}
	}
	s.insert({n * m, 1});
	fill(dis + 2, dis + k + 1, N * N);
	mark[1] = true;
	int ans = n * m;
	while (s.size()) {
		int v = (*s.begin()).second;
		s.erase(s.begin());
		vec.push_back({v, par[v]});
		ans += dis[v];
		mark[v] = true;
		for (auto p : adj[v]) {
			int u = p.first, w = p.second;
			if (w < dis[u] && !mark[u]) {
				if (w == n * m) {
					par[u] = 0;
				}
				else {
					par[u] = v;
				}
				s.erase({dis[u], u});
				dis[u] = w;
				s.insert({dis[u], u});
			}
		}
	}
	cout << ans << endl;
	for (auto p : vec) {
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}