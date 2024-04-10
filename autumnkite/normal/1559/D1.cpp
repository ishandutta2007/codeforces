#include <bits/stdc++.h>

class DSU {
	std::vector<int> fa;

public:
	DSU(int n) : fa(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		if (x > y) {
			std::swap(x, y);
		}
		fa[y] = x;
		return true;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m1, m2;
	std::cin >> n >> m1 >> m2;
	DSU D1(n), D2(n);
	for (int i = 0; i < m1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		D1.merge(u, v);
	}
	for (int i = 0; i < m2; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		D2.merge(u, v);
	}

	std::vector<std::vector<int>> S1(n), S2(n);
	std::set<int> S, T1, T2;
	for (int i = 1; i < n; ++i) {
		S.insert(i);
	}
	auto add1 = [&](int x) {
		if (S.count(x)) {
			S.erase(x);
		}
		if (T2.count(x)) {
			T2.erase(x);
		} else {
			T1.insert(x);
		}
	};
	auto add2 = [&](int x) {
		if (S.count(x)) {
			S.erase(x);
		}
		if (T1.count(x)) {
			T1.erase(x);
		} else {
			T2.insert(x);
		}
	};
	for (int i = 0; i < n; ++i) {
		S1[D1.find(i)].push_back(i);
		S2[D2.find(i)].push_back(i);
	}
	for (int x : S1[0]) {
		add1(x);
	}
	for (int x : S2[0]) {
		add2(x);
	}
	std::vector<std::pair<int, int>> ans;
	while ((int)S.size() >= 1 || ((int)T1.size() >= 1 && (int)T2.size() >= 1)) {
		if ((int)S.size() >= 1) {
			int u = *S.begin();
			ans.emplace_back(0, u);
			for (int x : S1[D1.find(u)]) {
				add1(x);
			}
			for (int x : S2[D2.find(u)]) {
				add2(x);
			}
		} else {
			auto u = *T1.begin(), v = *T2.begin();
			ans.emplace_back(u, v);
			for (int x : S1[D1.find(v)]) {
				add1(x);
			}
			for (int x : S2[D2.find(u)]) {
				add2(x);
			}
		}
	}
	std::cout << ans.size() << "\n";
	for (auto [u, v] : ans) {
		std::cout << u + 1 << " " << v + 1 << "\n";
	}
}