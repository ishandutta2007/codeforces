#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 100 * 1000 + 5;
const long long inf = 1000ll * 1000 * 1000 * 1000 * 1000 + 5;


long long dis[N];
vector <pair <int, int> > adj[N];
multiset <pair <long long, pair <bool, int> > > s;


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		
	}
	for (int i = 1; i <= k; i++) {
		int v, w;
		cin >> v >> w;
		s.insert({w, {1, v}});
	}
	s.insert({0, {0, 1}});
	int ans = 0;
	fill(dis + 2, dis + n + 1, inf);
	while (s.size()) {
		pair <long long, pair <bool, int> > p = *s.begin();
		s.erase(s.begin());
		int v = p.second.second, x = p.first;
	//	cout << v << " " << p.second.first << " " << x << endl;
		if (p.second.first) {
			if (x < dis[v]) {
				dis[v] = x;
			}
			else {
				ans++;
				continue;
			}
		}
		for (auto p2 : adj[v]) {
			int u = p2.first, w = p2.second;
			if (dis[v] + w < dis[u]) {
				s.erase({dis[u], {0, u}});
				dis[u] = dis[v] + w;
				s.insert({dis[u], {0, u}});
			}
		}
	}
	cout << ans;
	return 0;	
}