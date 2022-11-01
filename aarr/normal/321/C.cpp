#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5, LG = 23;
int sz, ctr;

vector <int> adj[N];
int dp[N][LG];
bool mark[N][LG];
int ans[N];


void dfs1(int v, int l) {
	dp[v][l] = 1;
	for (auto u : adj[v]) {
		if (dp[u][l] == 0 && ans[u] == 0) {
			dfs1(u, l);
			dp[v][l] += dp[u][l];
		}
	}
}
void dfs2(int v, int l) {
	mark[v][l] = true;
	int maxi = 0, s = 0;
	for (auto u : adj[v]) {
		if (!mark[u][l] && ans[u] == 0) {
			dfs2(u, l);
			maxi = max(maxi, dp[u][l]);
			s += dp[u][l];
		}
	}
	maxi = max(maxi, sz - s - 1);
	if (maxi <= sz / 2) {
		ctr = v;
	}
}
void solve(int v, int l) {
	ctr = -1;
	dfs1(v, l);
	sz = dp[v][l];
//	cout << "73 " << v << endl;
	dfs2(v, l);
	ans[ctr] = l;
//	cout << v << " " << ctr << " " << l << endl;
	for (auto u : adj[ctr]) {
		if (ans[u] == 0) {
			solve(u, l + 1);
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
	solve(1, 1);
	for (int i = 1; i <= n; i++) {
		cout << (char) ('A' + ans[i] - 1) << " ";
	}
	return 0;
}