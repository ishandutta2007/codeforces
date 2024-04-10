#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> p(n + 1);
	p[0] = n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> p[i];
	}
	std::vector<int> a(n + 1), b(n + 1);
	std::vector<long long> val(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		std::cin >> b[i];
	}

	int LG = 1;
	while ((1 << LG) <= n) {
		++LG;
	}
	std::vector<std::vector<int>> fa(LG, std::vector<int>(n + 1, -1));
	std::vector<int> dep(n + 1);
	std::vector<int> sta;
	sta.push_back(0);
	for (int i = 1; i <= n; ++i) {
		while ((int)sta.size() > 1 && p[sta.back()] < p[i]) {
			sta.pop_back();
		}
		fa[0][i] = sta.back();
		val[i] += a[i] - b[i];
		val[fa[0][i]] += b[i];
		dep[i] = dep[fa[0][i]] + 1;
		for (int j = 1; j < LG; ++j) {
			fa[j][i] = fa[j - 1][i] == -1 ? -1 : fa[j - 1][fa[j - 1][i]];
		}
		sta.push_back(i);
	}

	for (int i = n; i >= 1; --i) {
		val[fa[0][i]] += std::min(0ll, val[i]);
		val[i] -= std::min(0ll, val[i]);
	}
	for (int i = 1; i <= n; ++i) {
		val[i] += val[fa[0][i]];
	}

	auto LCA = [&](int u, int v) {
		if (dep[u] < dep[v]) {
			std::swap(u, v);
		}
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[i][u] != -1 && dep[fa[i][u]] >= dep[v]) {
				u = fa[i][u];
			}
		}
		if (u == v) {
			return u;
		}
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[i][u] != fa[i][v]) {
				u = fa[i][u];
				v = fa[i][v];
			}
		}
		return fa[0][u];
	};
	auto dis = [&](int u, int v) {
		return val[u] + val[v] - 2 * val[LCA(u, v)];
	};

	std::vector<bool> vis(n + 1);
	std::vector<int> cnt(n + 1);
	std::set<int> S;
	cnt[0] = 1, S.insert(0);
	long long ans = 0;

	auto insert = [&](int x) {
		auto it = S.insert(x).first, pr = std::prev(it), nx = std::next(it);
		if (nx == S.end()) {
			nx = S.begin();
		}
		ans += dis(*pr, *it) + dis(*it, *nx) - dis(*pr, *nx);
	};
	auto erase = [&](int x) {
		auto it = S.find(x), pr = std::prev(it), nx = std::next(it);
		if (nx == S.end()) {
			nx = S.begin();
		}
		ans -= dis(*pr, *it) + dis(*it, *nx) - dis(*pr, *nx);
		S.erase(it);
	};

	while (q--) {
		int x;
		std::cin >> x;
		if (!vis[x]) {
			vis[x] = true;
			if (!cnt[fa[0][x]]) {
				insert(fa[0][x]);
			}
			++cnt[fa[0][x]];
		} else {
			vis[x] = false;
			--cnt[fa[0][x]];
			if (!cnt[fa[0][x]]) {
				erase(fa[0][x]);
			}
		}
		std::cout << ans / 2 + val[0] << "\n";
	}
}