#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int N = 500 * 1000 + 5;
int ans;

vector <int> adj[N];
int dp[N];
int h[N];
bool mark[N];
vector <int> vec;

int dfs(int v) {
	mark[v] = true;
	if (adj[v].size() == 1) {
		dp[v] = 1;
		vec.push_back(h[v]);
	}
	for (auto u : adj[v]) {
		if (!mark[u]) {
			h[u] = h[v] + 1;
			dfs(u);
			dp[v] += dp[u];
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
	mark[1] = true;
	for (auto u : adj[1]) {
		dfs(u);
		sort(vec.begin(), vec.end());
		int t = 0;
		for (int i = 0; i < vec.size(); i++) {
			t = max(t, vec[i]);
			t++;
		}
		ans = max(ans, t);
		vec.clear();
	}
	cout << ans;
	return 0;
}