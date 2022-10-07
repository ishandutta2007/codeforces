#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> l(n, n), r(n, -1);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
		l[a[i]] = std::min(l[a[i]], i);
		r[a[i]] = std::max(r[a[i]], i);
	}

	std::vector<int> f(n + 1);
	std::vector<int> cnt(n);
	for (int i = n - 1; i >= 0; --i) {
		++cnt[a[i]];
		if (i == l[a[i]]) {
			f[i] = std::max(f[i + 1], f[r[a[i]] + 1] + cnt[a[i]]);
		} else {
			f[i] = std::max(f[i + 1], cnt[a[i]]);
		}
	}
	
	std::cout << n - f[0] << "\n";
}