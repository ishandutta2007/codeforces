#include <iostream>
#include <vector>
using namespace std;

const int N = 5005;

int nl[N];
int dp[N][N];
int a[N];
bool mark[N];
vector <int> adj[N];

void dfs(int v) {
	mark[v] = true;
	if (adj[v].size() == 1) {
		nl[v] = 1;
		dp[v][0] = N;
		return;
	}
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
			for (int i = 0; i <= nl[v] + nl[u]; i++) {
				a[i] = dp[v][i];
				dp[v][i] = N;
			}
			for (int i = 0; i <= nl[v]; i++) {
				for (int j = 0; j <= nl[u]; j++) {
					dp[v][i + j] = min(dp[v][i + j], a[i] + dp[u][j]);
					dp[v][i + nl[u] - j] = min(dp[v][i + nl[u] - j], a[i] + dp[u][j] + 1);
				}
			}
			nl[v] += nl[u];
		}
	}
	
	
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (n == 2) {
		cout << 1;
		return 0;
	}
	int v;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() > 1) {
			v = i;
		}
	}
	dfs(v);
	cout << dp[v][nl[v] / 2];
	return 0;
}