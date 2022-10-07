#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::string s;
	std::cin >> s;
	int n = s.size();

	std::vector<int> a(n + 1);
	for (int i = 0; i < n; ++i) {
		a[i + 1] = a[i] + (s[i] == '1');
	}

	const int B = sqrt(n);

	std::vector<int> cnt(n * B + 1);
	long long ans = 0;
	for (int d = 0; d < B; ++d) {
		for (int i = 0; i <= n; ++i) {
			int v = d * a[i] + n - i;
			ans += cnt[v];
			++cnt[v];
		}
		for (int i = 0; i <= n; ++i) {
			int v = d * a[i] + n - i;
			--cnt[v];
		}
	}
	for (int d = 1; d <= n / B; ++d) {
		for (int l = 0, r1 = 0, r2 = 0; l <= n; ++l) {
			while (r1 <= n && a[r1] - a[l] < d) {
				++r1;
			}
			while (r2 <= n && a[r2] - a[l] <= d) {
				++r2;
			}
			int L = (r1 - l - 1) / d, R = (r2 - l - 1) / d;
			L = std::max(L, B - 1);
			ans += std::max(R - L, 0);
		}
	}
	std::cout << ans << "\n";
}