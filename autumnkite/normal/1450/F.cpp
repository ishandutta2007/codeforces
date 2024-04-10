#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n), cnt(n), cp(n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
			--a[i];
			++cnt[a[i]];
			if (i > 0 && a[i] == a[i - 1]) {
				cp[a[i]] += 2;
				++ans;
			}
		}
		++cp[a[0]], ++cp[a[n - 1]];
		if (*std::max_element(cnt.begin(), cnt.end()) > (n + 1) / 2) {
			std::cout << -1 << "\n";
		} else {
			std::cout << ans + std::max(0, *std::max_element(cp.begin(), cp.end()) - ans - 2) << "\n";
		}
	}
}