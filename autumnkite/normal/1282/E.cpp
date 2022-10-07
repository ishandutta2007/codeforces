#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::array<int, 3>> a(n - 2);
	std::vector<std::vector<int>> id(n);
	for (int i = 0; i < n - 2; ++i) {
		int x, y, z;
		std::cin >> x >> y >> z;
		--x, --y, --z;
		a[i] = {x, y, z};
		id[x].push_back(i);
		id[y].push_back(i);
		id[z].push_back(i);
	}

	std::vector<bool> vis(n - 2);
	std::vector<int> cnt(n);
	std::vector<int> q;
	std::vector<int> Q;
	for (int i = 0; i < n; ++i) {
		cnt[i] = id[i].size();
		if (cnt[i] == 1 && (int)Q.size() < n - 3) {
			Q.push_back(i);
		}
	}
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		for (int x : id[u]) {
			if (!vis[x]) {
				q.push_back(x);
				vis[x] = true;
				for (int v : a[x]) {
					--cnt[v];
					if (cnt[v] == 1 && (int)Q.size() < n - 3) {
						Q.push_back(v);
					}
				}
				break;
			}
		}
	}
	
	std::vector<int> p;
	for (int i = 0; i < n - 2; ++i) {
		if (!vis[i]) {
			q.push_back(i);
			for (int v : a[i]) {
				p.push_back(v);
			}
		}
	}
	for (int i = (int)Q.size() - 1; i >= 0; --i) {
		int u = Q[i];
		std::vector<int> nd;
		for (int v : a[q[i]]) {
			if (v != u) {
				nd.push_back(v);
			}
		}
		for (int j = 0; j < (int)p.size(); ++j) {
			if ((p[j] == nd[0] && p[(j + 1) % p.size()] == nd[1]) || 
			    (p[j] == nd[1] && p[(j + 1) % p.size()] == nd[0])) {
				p.insert(p.begin() + j + 1, u);
				break;
			}
		}
	}
	for (int x : p) {
		std::cout << x + 1 << " ";
	}
	std::cout << "\n";
	for (int x : q) {
		std::cout << x + 1 << " ";
	}
	std::cout << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}