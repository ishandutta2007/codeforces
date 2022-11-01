#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 200 * 1000 + 5;


vector <pair <int, int> > adj[N];
int w[N];
int d[N];
bool mark[N];
set <pair <int, int> > s;
vector <int> ans;


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	for (int i = 1; i <= n; i++) {
		d[i] = (int) adj[i].size() - w[i];
		s.insert({d[i], i});
	}
	while (s.size()) {
		int v = (*s.begin()).second;
		s.erase(s.begin());
		mark[v] = true;
		if (d[v] > 0) {
			cout << "DEAD";
			return 0;
		}
		for (auto p : adj[v]) {
			int u = p.first;
			if (!mark[u]) {
				s.erase({d[u], u});
				d[u]--;
				s.insert({d[u], u});
				ans.push_back(p.second);
			}
		}
	}
	cout << "ALIVE\n";
	reverse(ans.begin(), ans.end());
	for (auto x : ans) {
		cout << x << " ";
	}
	return 0;
}