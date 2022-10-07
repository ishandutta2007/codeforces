#include <bits/stdc++.h>

void solve() {
	int m, n;
	std::cin >> m >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int mx = *std::max_element(a.begin(), a.end());

	auto check = [&](int x) {
		long long c1 = 1ll * ((x + 1) / 2) * (x / 2);
		long long c2 = 1ll * ((x + 1) / 2) * ((x + 1) / 2);
		return mx <= c1 + c2 && m <= c1 * 2 + c2;
	};

	int l = 1, r = m, x = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			x = mid;
		} else {
			l = mid + 1;
		}
	}

	std::vector<int> val;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < a[i]; ++j) {
			val.push_back(i);
		}
	}
	std::sort(val.begin(), val.end(), [&](int x, int y) {
		return a[x] < a[y] || (a[x] == a[y] && x < y);
	});

	std::vector<std::vector<int>> ans(x, std::vector<int>(x, -1));
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			if (!(i & 1) && (j & 1) && !val.empty()) {
				ans[i][j] = val.back();
				val.pop_back();
			}
		}
	}
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			if (!(i & 1) && !(j & 1) && !val.empty()) {
				ans[i][j] = val.back();
				val.pop_back();
			}
		}
	}
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			if ((i & 1) && !(j & 1) && !val.empty()) {
				ans[i][j] = val.back();
				val.pop_back();
			}
		}
	}
	std::cout << x << "\n";
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			std::cout << ans[i][j] + 1 << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}