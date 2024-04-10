#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, L;
	std::cin >> n >> m >> L;
	std::vector<int> l(m), r(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> l[i] >> r[i];
		--l[i];
	}

	int ans = 0;
	for (int k = 0; k <= n; ++k) {
		std::vector<int> a(n + 1), b(n + 1);
		for (int i = 0; i < m; ++i) {
			if (k - l[i] >= r[i] - k) {
				++a[l[i]], --a[r[i]];
			} else {
				++b[l[i]], --b[r[i]];
			}
		}
		auto calc = [&](std::vector<int> a) {
			for (int i = 1; i < n; ++i) {
				a[i] += a[i - 1];
			}
			int sum = 0, mx = 0;
			for (int i = 0; i < n; ++i) {
				if (i >= L) {
					sum -= a[i - L];
				}
				sum += a[i];
				mx = std::max(mx, sum);
			}
			return mx;
		};
		ans = std::max(ans, calc(a) + calc(b));
	}
	std::cout << ans << "\n";
}