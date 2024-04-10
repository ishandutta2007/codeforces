#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a, b;
	for (int i = 0; i < n; ++i) {
		int tx, ty;
		std::cin >> tx >> ty;
		int x = tx + ty, y = tx - ty;
		if (x & 1) {
			a.emplace_back((x - 1) / 2, (y - 1) / 2);
		} else {
			b.emplace_back(x / 2, y / 2);
		}
	}
	
	auto get_ans = [&](std::vector<std::pair<int, int>> a) -> long long {
		if (a.empty()) {
			return 0;
		}
		std::sort(a.begin(), a.end());
		int n = a.size();
		std::vector<int> pmx(n), pmn(n);
		pmx[0] = pmn[0] = a[0].second;
		for (int i = 1; i < n; ++i) {
			pmx[i] = std::max(pmx[i - 1], a[i].second);
			pmn[i] = std::min(pmn[i - 1], a[i].second);
		}
		std::vector<int> smx(n), smn(n);
		smx[n - 1] = smn[n - 1] = a[n - 1].second;
		for (int i = n - 2; i >= 0; --i) {
			smx[i] = std::max(smx[i + 1], a[i].second);
			smn[i] = std::min(smn[i + 1], a[i].second);
		}
		long long ans = 0;
		for (int i = 0; i < n - 1; ++i) {
			ans += 1ll * (a[i + 1].first - a[i].first) * 
			       std::max(0, std::min(pmx[i], smx[i + 1]) - std::max(pmn[i], smn[i + 1]));
		}
		return ans;
	};

	std::cout << get_ans(a) + get_ans(b) << "\n";
}