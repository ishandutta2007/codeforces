#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int N = 100 * 1000 + 5;
const long long inf = 1000ll * 1000 * 1000 * 1000 + 5;

long long dis[N];
int par[N];
vector <pair <long long, int> > adj[N];
set <pair <int, int> > s;
map <pair <int, int> , int> mp;

int main() {
	int n, m, c = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		w = 1 - w;
		if (w == 0) {
			c++;
		}
		adj[u].push_back({v, N + w});
		adj[v].push_back({u, N + w});
	}
	fill(dis + 2, dis + n + 1, inf);
	s.insert({0, 1});
	while (s.size()) {
		pair <int, int> p = *s.begin();
		s.erase(s.begin());
		int v = p.second;
		for (int i = 0; i < adj[v].size(); i++) {
			int u = adj[v][i].first, w = adj[v][i].second;
			if (dis[v] + w < dis[u]) {
				s.erase({dis[u], u});
				dis[u] = dis[v] + w;
				s.insert({dis[u], u});
				par[u] = v;
			}
		}
	}
	int v = n, x = 0;
	while (v != 1) {
		mp[{v, par[v]}] = 1;
		mp[{par[v], v}] = 1;
		v = par[v];
	}
	long long a = dis[n] % N, b = dis[n] / N;
	cout << c - (b - a) + a << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int u = adj[i][j].first;
			if (i < u && mp[{i, u}] == 1 && adj[i][j].second == N + 1) {
				cout << i << " " << u << " " << 1 << endl;
			}
			if (i < u && mp[{i, u}] != 1 && adj[i][j].second == N) {
				cout << i << " " << u << " " << 0 << endl;
			}
		}
	}
	return 0;
}