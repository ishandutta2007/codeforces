#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>

using namespace std;
typedef long long ll;

int n;
vector<int> adj[(int)2e5 + 1];
int dp[(int)2e5 + 1];

void dfs(int u, int p) {
	adj[u].erase(remove(adj[u].begin(), adj[u].end(), p), adj[u].end());
	dp[u] = 0;
	for (auto &&v : adj[u]) {
		dfs(v, u);
		dp[u] ^= !dp[v];
	}
}

void dfs2(int u) {
	for (auto &&v : adj[u])
		if (dp[v])
			dfs2(v);
	cout << '\n' << u;
	for (auto &&v : adj[u])
		if (!dp[v])
			dfs2(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof dp);

	cin >> n;
	int root;
	for (int i = 1; i <= n; ++i) {
		int p;
		cin >> p;
		if (!p)
			root = i;
		else {
			adj[i].push_back(p);
			adj[p].push_back(i);
		}
	}
	dfs(root, -1);
	if (dp[root])
		cout << "NO";
	else {
		cout << "YES";
		dfs2(root);
	}
	return 0;
}