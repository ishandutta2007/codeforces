#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<set<int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].insert(v);
		g[v].insert(u);
	}

	set<int> vul;
	for (int i = 0; i < n; i++) {
		if (g[i].empty() || *g[i].rbegin() < i) vul.insert(i);
	}

	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 3) {
			cout << vul.size() << '\n';
		} else if (type == 1) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			g[u].insert(v);
			g[v].insert(u);
			if (g[u].empty() || *g[u].rbegin() < u) vul.insert(u);
			else vul.erase(u);
			if (g[v].empty() || *g[v].rbegin() < v) vul.insert(v);
			else vul.erase(v);
			// cout << vul.size() << endl;
		} else {
			int u, v;
			cin >> u >> v;
			u--, v--;
			g[u].erase(v);
			g[v].erase(u);
			if (g[u].empty() || *g[u].rbegin() < u) vul.insert(u);
			else vul.erase(u);
			if (g[v].empty() || *g[v].rbegin() < v) vul.insert(v);
			else vul.erase(v);
			// cout << vul.size() << endl;
		}
	}

	return 0;
}