#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}

	auto check = [&](long long x) {
		std::vector<std::vector<int>> id(m);
		std::vector<long long> now(a);
		auto add = [&](int i) {
			if (now[i] / b[i] < m) {
				id[now[i] / b[i]].push_back(i);
			}
		};
		for (int i = 0; i < n; ++i) {
			add(i);
		}
		int c = 0;
		for (int i = 0; i < m - 1; ++i) {
			++c;
			while (!id[i].empty() && c) {
				int p = id[i].back();
				id[i].pop_back();
				now[p] += x;
				--c;
				add(p);
			}
			if (!id[i].empty()) {
				return false;
			}
		}
		return true;
	};

	long long l = 0, r = 2e12, ans = -1;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	std::cout << ans << "\n";
}