#include <iostream>
#include <vector>
using namespace std;

const int N = 3005;
int c;


vector <pair <int, int> > adj[N];
bool mark[N];
int d[N];

void dfs(int v) {
	mark[v] = true;
	for (auto p : adj[v]) {
		int u = p.first;
		if (!mark[u]) {
			if (p.second == 1) {
				d[u] = d[v] + 1;
				c++;
			}
			else {
				d[u] = max(0, d[v] - 1);
			}
			dfs(u);
		}
	}
}

int main() {
	int n, ans = N;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, 0});
		adj[v].push_back({u, 1});
	}
	for (int i = 1; i <= n; i++) {
		fill(mark, mark + n + 1, false);
		fill(d, d + n + 1, 0);
		c = 0;
		dfs(i);
		int x = 0;
		for (int j = 1; j <= n; j++) {
			x = max(x, d[j]);
		}
		ans = min(ans, c - x);
	//	cout << i << " " << c << " " << x << endl;
	}
	cout << ans;
	return 0;
}