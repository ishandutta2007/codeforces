#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;

vector <pair <int, int> > adj[N];
bool mark[N];
vector <int> vec;


void dfs(int v) {
	if (mark[v]) {
		return;
	}
	mark[v] = true;
	for (auto p : adj[v]) {
		dfs(p.first);
	}
	vec.push_back(v);
}
int main() {
	int n, m;
	cin >> n >> m;
	int c1 = n, c2 = n;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});

	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
	int ans = 0;
	for (int i = n - 1; i; i--) {
		int v = vec[i], u = vec[i - 1], x = N;
		for (auto p : adj[v]) {
			if (p.first == u) {
				x = p.second;
			}
		}
		ans = max(ans, x);
	}
	if (ans == N) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}