#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 100 * 1000 + 5, inf = 1000 * 1000 * 1000 + 7;

vector <pair <int, int> > adj[N];
int dis[N];
set <pair <int, int > > s;

int main() {
	int n, m, st;
	cin >> n >> m >> st;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	fill(dis + 1, dis + n + 1, inf);
	dis[st] = 0;
	s.insert({0, st});
	while (s.size()) {
		int v = (*s.begin()).second;
		s.erase(s.begin());
		for (auto p : adj[v]) {
			int u = p.first, w = p.second;
			if (dis[v] + w < dis[u]) {
				s.erase({dis[u], u});
				dis[u] = dis[v] + w;
				s.insert({dis[u], u});
			}
		}
	}
	int l, ans = 0;
	cin >> l;
//	for (int i = 1; i <= n; i++) {
//		cout << "48 " << i << " " << dis[i] << endl;
//	}
	for (int i = 1; i <= n; i++) {
		if (dis[i] == l) {
			ans -= adj[i].size() - 1;
		}
		for (auto p : adj[i]) {
			int u = p.first, v = i, w = p.second;
			if (v > u) {
				if (dis[u] > dis[v]) {
					swap(u, v);
				}
				double d = (double) (w - dis[v] + dis[u]) / 2;
				if (l == dis[v] + d) {
					ans++;
				//	cout << "51 " << " " << v << endl;
				}
				if (dis[v] <= l && l < dis[v] + d) {
					ans += 2;
				}
				if (dis[u] <= l && l < dis[v]) {
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}