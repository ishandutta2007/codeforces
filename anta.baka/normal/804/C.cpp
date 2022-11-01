#include <bits/stdc++.h>

using namespace std;

int n, m, s, u, v, ans = 1, col[300000];
vector<int> t[300000], g[300000]; 

void dfs(int v, int p) {
	set<int> ban;
	for(int x : t[v]) {
		ban.insert(col[x]);
	}
	int c = 1;
	for(int x : t[v]) {
		if(col[x]) {
			continue;
		}
		while(ban.find(c) != ban.end()) {
			c++;
		}
		col[x] = c++;
	}
	for(int to : g[v]) {
		if(to == p) {
			continue;
		}
		dfs(to, v);
	}
}

main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s;
		t[i].resize(s);
		ans = max(ans, s);
		for(int j = 0; j < s; j++) {
			cin >> t[i][j];
			--t[i][j];
		}
	}
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	cout << ans << '\n';
	for(int i = 0; i < m; i++) {
		cout << max(1, col[i]) << ' ';
	}
}