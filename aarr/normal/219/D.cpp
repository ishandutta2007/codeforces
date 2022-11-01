#include <iostream>
#include <vector>
using namespace std;

const int N = 200 * 1000 + 5;

int par[N];
int dp[N];
int ans[N];
vector <pair <int, int> > adj[N];
void dfs1(int v) {
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i].first, dir = adj[v][i].second;
		if (u != par[v]) {
			par[u] = v;
			dfs1(u);
			dp[v] += dp[u];
			if (!dir) {
				dp[v]++;
			}
		}
	}
}
void dfs2(int v) {
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i].first, dir = adj[v][i].second;
		if (u != par[v]) {
			ans[u] = ans[v];
			if (dir) {
				ans[u]++;
			}
			else {
				ans[u]--;
			}
			dfs2(u);
		}
	}
}
int main() {
	int n, finans = N;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, 1});
		adj[v].push_back({u, 0});
	}
	dfs1(1);
	ans[1] = dp[1];
	dfs2(1);
	for (int i = 1; i <= n; i++) {
		finans = min(finans, ans[i]);
	}
	cout << finans << endl;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == finans) {
			cout << i << " ";
		}
	}	
	return 0;
}