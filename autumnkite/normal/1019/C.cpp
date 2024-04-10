#include <bits/stdc++.h>

const int N = 1000005;

int n, m;
std::vector<int> E[N];
bool ex[N], vis[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		E[u].push_back(v);
	}

	for (int i = 1; i <= n; ++i) {
		ex[i] = true;
	}
	std::vector<int> v;
	for (int i = 1; i <= n; ++i) {
		if (ex[i]) {
			v.push_back(i);
			ex[i] = false;
			for (int v : E[i]) {
				ex[v] = false;
			}
		}
	}

	std::reverse(v.begin(), v.end());
	for (int i = 1; i <= n; ++i) {
		vis[i] = false;
	}
	std::vector<int> ans;
	for (int i : v) {
		if (!vis[i]) {
			ans.push_back(i);
			for (int v : E[i]) {
				vis[v] = true;
			}
		}
	}

	std::cout << ans.size() << "\n";
	for (int v : ans) {
		std::cout << v << " ";
	}
	std::cout << "\n";
}