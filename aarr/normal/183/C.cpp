#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;
int ans = 0;

vector <pair <int, int> > adj[N];
pair <int, int>  inc;
bool mark[N];
int a[N];
int bmm(int x, int y) {
	if (y == 0)
		return x;
	return bmm(y, x % y);
}
bool dfs(int v) {
//	cout << v << endl;
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i].first, d = adj[v][i].second;
		if (!mark[u]) {
			a[u] = a[v] + d;
			dfs(u);
		}
		else {
		//	cout << v << " " << u << endl;
			ans = bmm(ans, abs(a[v] + d - a[u]));
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, 1});
		adj[v].push_back({u, -1});
	}
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			dfs(i);
		}
	}
	if (ans == 0) {
		cout << n << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}