#include<bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, res[N], ans = 0;
bool sta[N];
vector<int> adj[N];

void dfs(int u) {
	if (adj[u].size() == 0) {
		res[u] = 1;
		ans++;
		return;
	}
	int t;
	if (sta[u] == 1) t = 1e9;
	else t = 0;
	for (auto v : adj[u]) {
		dfs(v);
		if (sta[u] == 1) {
			t = min(t, res[v]);
		} else {
			t += res[v];
		}
	}
	res[u] = t;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sta[i];
	}
	for (int i = 2; i <= n; i++) {
		int u;
		cin >> u;
		adj[u].push_back(i);
	}
	dfs(1);
	cout << ans + 1 - res[1];
	return 0;
}