#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
		--p[i];
	}

	std::vector<int> nx(n, -1), pr(n, -1);
	bool flag = false;
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		if (nx[u] != -1 || pr[v] != -1) {
			flag = true;
		}
		nx[u] = v, pr[v] = u;
	}
	if (flag) {
		std::cout << 0 << "\n";
		return 0;
	}

	std::vector<int> hd(n, -1), id(n, -1);
	for (int i = 0; i < n; ++i) {
		if (pr[i] == -1) {
			int now = 0;
			for (int j = i; j != -1; j = nx[j]) {
				hd[j] = i;
				id[j] = now++;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (hd[i] == -1) {
			std::cout << 0 << "\n";
			return 0;
		}
	}

	std::vector<std::vector<int>> E(n);
	std::vector<int> deg(n);
	for (int i = 0; i < n; ++i) {
		if (p[i] != -1) {
			if (hd[p[i]] != hd[i]) {
				E[hd[p[i]]].push_back(hd[i]);
				++deg[hd[i]];
			} else if (id[p[i]] >= id[i]) {
				std::cout << 0 << "\n";
				return 0;
			}
		}
	}
	std::vector<int> Q;
	for (int i = 0; i < n; ++i) {
		if (hd[i] == i && !deg[i]) {
			Q.push_back(i);
		}
	}
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		for (int v : E[u]) {
			--deg[v];
			if (!deg[v]) {
				Q.push_back(v);
			}
		}
	}
	std::vector<int> ans;
	for (int u : Q) {
		for (int v = u; v != -1; v = nx[v]) {
			ans.push_back(v);
		}
	}
	if ((int)ans.size() != n) {
		std::cout << 0 << "\n";
	} else {
		for (int v : ans) {
			std::cout << v + 1 << " ";
		}
		std::cout << "\n";
	}
}