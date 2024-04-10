#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Mx = (int) 2e5 + 9;
vector<int> adj[Mx + 9];
int vis[Mx + 9];

void dfs1(const int u, const int t) {
	vis[u] = t;
	for (const int &v : adj[u])
		if (!vis[v])
			dfs1(v, t);
}

void dfs2(const int u) {
	vis[u] = 1;
	for (const int &v : adj[u])
		if (!vis[v]) {
			cout << u << ' ' << v << '\n';
			dfs2(v);
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, D;
	cin >> n >> m >> D;

	vector<int> nodes;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v)
			swap(u, v);
		if (u == 1)
			nodes.push_back(v);
		else {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	int t = 0;
	for (int x : nodes)
		if (!vis[x])
			dfs1(x, ++t);

	if (D < t || D > (int) nodes.size()) {
		cerr << D << ' ' << t << ' ' << nodes.size() << endl;
		cout << "NO";
		return 0;
	}
	cout << "YES\n";

	map<int, vector<int>> mp;
	for (int x : nodes)
		mp[vis[x]].push_back(x);

	nodes.clear();

	for (auto &&e : mp) {
		nodes.push_back(e.second.back());
		e.second.pop_back();
		D--;
	}

	for (auto &&e : mp) {
		for (int x : e.second) {
			if (!D)
				break;
			D--;
			nodes.push_back(x);
		}
	}

	assert(!D);

	memset(vis, 0, sizeof vis);

	vis[1] = true;
	for (int v : nodes) {
		cout << 1 << ' ' << v << '\n';
		vis[v] = true;
	}
	for (int v : nodes)
		dfs2(v);
	return 0;
}