#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int S;
vector<vector<int>> G;
vector<int> a;

void solve() {
	cin >> n;
	S = 0;
	G.clear();
	G.resize(n);
	a.clear();
	a.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	queue<pair<int, int>> q;
	q.push({0, -1});
	while (!q.empty()) {
		auto qq = q.front();
		q.pop();
		int v = qq.first;
		int p = qq.second;
		vector<int> tos;
		for (int to : G[v])
			if (to != p)
				tos.push_back(to);

		if (p == -1) {
			a[0] = -tos.size();
			int to_add = 1;
			S = a[v] + tos.size() * to_add;
			for (auto to : tos) {
				a[to] += to_add;
				q.push({to, v});
			}
		} else {
			int to_add = S - a[v];
			a[v] -= to_add * tos.size();
			for (auto to : tos) {
				a[to] += to_add;
				q.push({to, v});
			}
		}
	}
	
	for (auto x : a)
		cout << x << ' ';
	cout << '\n';
}


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}