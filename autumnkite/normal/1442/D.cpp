#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n);
	std::vector<long long> sum(n);
	for (int i = 0; i < n; ++i) {
		int k;
		std::cin >> k;
		a[i].resize(k);
		for (int &v : a[i]) {
			std::cin >> v;
			sum[i] += v;
		}
	}
	auto upd = [&](std::vector<long long> &f, int w, long long v) {
		for (int i = (int)f.size() - 1; i >= w; --i) {
			f[i] = std::max(f[i], f[i - w] + v);
		}
		return;
	};
	std::function<long long(int, int, std::vector<long long>)> solve = [&](int l, int r, std::vector<long long> f) {
		if (l + 1 == r) {
			long long res = f[m];
			long long now = 0;
			for (int i = 0; i < (int)a[l].size() && i < m; ++i) {
				now += a[l][i];
				res = std::max(res, f[m - i - 1] + now);
			}
			return res;
		}
		int mid = (l + r + 1) >> 1;
		auto gA = f, gB = f;
		for (int i = mid; i < r; ++i) {
			upd(gA, a[i].size(), sum[i]);
		}
		for (int i = l; i < mid; ++i) {
			upd(gB, a[i].size(), sum[i]);
		}
		return std::max(solve(l, mid, gA), solve(mid, r, gB));
	};
	std::cout << solve(0, n, std::vector<long long>(m + 1)) << "\n";
}