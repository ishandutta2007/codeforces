#include <bits/stdc++.h>

std::pair<long long, long long> get_frac(long long a, long long b) {
	long long g = std::__gcd(a, b);
	return std::make_pair(a / g, b / g);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<long long, long long>> vec, t1(n), t2(n);
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		vec.push_back(t1[i] = get_frac(1ll * (a + b) * d, 1ll * b * c));
		vec.push_back(t2[i] = get_frac(1ll * a * d, 1ll * b * (c + d)));
	}

	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

	std::vector<std::vector<std::pair<int, int>>> E(vec.size());
	for (int i = 0; i < n; ++i) {
		int u = std::lower_bound(vec.begin(), vec.end(), t1[i]) - vec.begin();
		int v = std::lower_bound(vec.begin(), vec.end(), t2[i]) - vec.begin();
		E[u].emplace_back(v, i);
		E[v].emplace_back(u, i);
	}

	std::vector<bool> vis(vec.size()), used(n);
	std::vector<std::pair<int, int>> ans;

	std::function<bool(int, int)> dfs = [&](int u, int fi) {
		vis[u] = true;
		int lst = -1;
		for (auto p : E[u]) {
			int v = p.first, id = p.second;
			if (id == fi || used[id]) {
				continue;
			}
			if (vis[v] || !dfs(v, id)) {
				if (lst == -1) {
					lst = id;
				} else {
					ans.emplace_back(lst, id);
					used[lst] = used[id] = true;
					lst = -1;
				}
			}
		}
		if (lst != -1 && fi != -1) {
			ans.emplace_back(lst, fi);
			used[lst] = used[fi] = true;
			return true;
		} else {
			return false;
		}
	};

	for (int i = 0; i < (int)vec.size(); ++i) {
		if (!vis[i]) {
			dfs(i, -1);
		}
	}
	std::cout << ans.size() << "\n";
	for (auto p : ans) {
		std::cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
}