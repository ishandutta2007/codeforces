#include <bits/stdc++.h>

const int N = 100005;
const int P = 19260817;

int n, m, K;
int d[N];
std::vector<int> hash[P];
std::vector<int> E[N];

bool check(const std::vector<int> &id) {
	for (int i = 0; i < (int)id.size(); ++i) {
		for (int j = i + 1; j < (int)id.size(); ++j) {
			int t = (1ll * id[i] * n + id[j]) % P;
			bool flag = 0;
			for (int v : hash[t]) {
				if (v == id[i]) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				return false;
			}
		}
	}
	return true;
}

void undo() {
	for (int i = 1; i <= n; ++i) {
		for (int j : E[i]) {
			hash[(1ll * i * n + j) % P].clear();
		}
	}
}

void solve() {
	std::cin >> n >> m >> K;
	for (int i = 1; i <= n; ++i) {
		E[i].clear();
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	if (1ll * K * (K - 1) / 2 > m) {
		std::cout << -1 << "\n";
		return;
	}
	for (int i = 1; i <= n; ++i) {
		d[i] = E[i].size();
		for (int j : E[i]) {
			hash[(1ll * i * n + j) % P].push_back(i);
		}
	}
	std::vector<int> S;
	for (int i = 1; i <= n; ++i) {
		if (d[i] < K) {
			S.push_back(i);
		}
	}
	while (!S.empty()) {
		int u = S.back();
		if (d[u] == K - 1) {
			std::vector<int> id;
			id.push_back(u);
			for (int v : E[u]) {
				if (~d[v] && d[v] >= K - 1) {
					id.push_back(v);
				}
			}
			if ((int)id.size() == K && check(id)) {
				std::cout << 2 << "\n";
				for (int v : id) {
					std::cout << v << " ";
				}
				std::cout << "\n";
				undo();
				return;
			}
		}
		S.pop_back();
		for (int v : E[u]) {
			if (~d[v]) {
				if (d[v] == K) {
					S.push_back(v);
				}
				--d[v];
			}
		}
		d[u] = -1;
	}
	std::vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (~d[i]) {
			ans.push_back(i);
		}
	}
	if (!ans.empty()) {
		std::cout << 1 << " " << ans.size() << "\n";
		for (auto v : ans) {
			std::cout << v << " ";
		}
		std::cout << "\n";
		undo();
		return;
	}
	std::cout << -1 << "\n";
	undo();
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}