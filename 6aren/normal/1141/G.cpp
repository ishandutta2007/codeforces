#include<bits/stdc++.h>

using namespace std;

int n, k, a[200005], r, res[200005];

vector<pair<int, int>> adj[200005];

bool cmp(int x, int y) {
	return adj[x].size() > adj[y].size();
}

void dfs(int u, int v, int c) {
	int check = 1;
	for (auto t : adj[u]) {
		if (t.first == v) continue;
		if (adj[u].size() > r) {
			res[t.second] = 1;
			dfs(t.first, u, 1);
			continue;
		}
		if (check == c) check++;
		res[t.second] = check;
		check++;
		dfs(t.first, u, check - 1);
	}
	return;	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(make_pair(v, i));
		adj[v].push_back(make_pair(u, i));
	}
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	sort(a + 1, a + n + 1, cmp);
	r = adj[a[k + 1]].size();
	cout << r << endl;
	dfs(1, 0, 0);
	for (int i = 1; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}