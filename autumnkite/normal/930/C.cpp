#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(m);
	for (int i = 0; i < n; ++i) {
		int l, r;
		std::cin >> l >> r;
		--l;
		++a[l];
		if (r < m) {
			--a[r];
		}
	}
	for (int i = 0; i < m; ++i) {
		a[i] += a[i - 1];
	}
	std::vector<int> b(m);
	std::reverse_copy(a.begin(), a.end(), b.begin());

	auto DP = [&](std::vector<int> a) {
		int n = a.size();
		std::vector<int> f(n);
		std::vector<int> mn(n + 1, *std::max_element(a.begin(), a.end()) + 1);
		mn[0] = 0;
		for (int i = 0; i < n; ++i) {
			int p = std::upper_bound(mn.begin(), mn.end(), a[i]) - mn.begin();
			f[i] = p;
			mn[p] = std::min(mn[p], a[i]);
		}
		return f;
	};

	std::vector<int> f(DP(a)), g(DP(b));
	std::reverse(g.begin(), g.end());
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		ans = std::max(ans, f[i] + g[i] - 1);
	}
	std::cout << ans << "\n";
}