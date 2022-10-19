// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

vector<int> g[N];

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int target = ceil(sqrtl(n) - 1e-9);

	vector<int> deg(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[v]++;
		deg[u]++;
	}

	set<pair<int, int>> kek;
	vector<int> is;
	for (int i = 1; i <= n; i++) {
		kek.insert({deg[i], i});
	}
	while (!kek.empty()) {
		int v = kek.begin()->second;
		kek.erase(kek.begin());
		is.push_back(v);
		for (int u : g[v]) {
			if (kek.count({deg[u], u})) {
				kek.erase({deg[u], u});
				for (int w : g[u]) {
					if (kek.count({deg[w], w})) {
						kek.erase({deg[w], w});
						deg[w]--;
						kek.insert({deg[w], w});
					}
				}
			}
		}
	}
	if (is.size() >= target) {
		cout << "1\n";
		for (int i = 0; i < target; i++) {
			cout << is[i] << " \n"[i + 1 == target];
		}
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		deg[i] = g[i].size();
		kek.insert({deg[i], i});
	}
	while (kek.begin()->first < target - 1) {
		int v = kek.begin()->second;
		kek.erase(kek.begin());
		for (int u : g[v]) {
			if (kek.count({deg[u], u})) {
				kek.erase({deg[u], u});
				deg[u]--;
				kek.insert({deg[u], u});
			}
		}
	}
	int start = kek.begin()->second;
	vector<int> path{start};
	vector<int> used(n + 1);
	used[start] = 1;
	int v = start;
	bool ok = true;
	while (ok) {
		ok = false;
		for (int u : g[v]) {
			if (!used[u] && kek.count({deg[u], u})) {
				used[u] = 1;
				path.push_back(u);
				v = u;
				ok = true;
				break;
			}
		}
	}
	
	start = path.back();
	vector<int> neighbour(n + 1);
	for (int u : g[start]) {
		neighbour[u] = 1;
	}
	for (int i = 0; i < path.size(); i++) {
		if (neighbour[path[i]]) {
			cout << "2\n";
			cout << path.size() - i << '\n';
			for (int j = i; j < path.size(); j++) {
				cout << path[j] << " \n"[j + 1 == path.size()];
			}
			return 0;
		}
	}
	return 0;
}