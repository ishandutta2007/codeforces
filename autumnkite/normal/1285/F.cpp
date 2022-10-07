#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int m = *std::max_element(a.begin(), a.end());

	std::vector<int> cnt(m + 1);
	for (int v : a) {
		cnt[v] = 1;
	}

	std::vector<std::vector<int>> d(m + 1);
	for (int i = 1; i <= m; ++i) {
		for (int j = i; j <= m; j += i) {
			d[j].push_back(i);
		}
	}
	std::vector<int> mu(m + 1);
	for (int i = 1; i <= m; ++i) {
		mu[i] += i == 1;
		for (int j = i + i; j <= m; j += i) {
			mu[j] -= mu[i];
		}
	}

	long long ans = 0;
	for (int i = 1; i <= m; ++i) {
		int c = m / i;
		std::vector<int> v(c + 1);
		for (int x = 1; x <= c; ++x) {
			for (int k : d[x]) {
				v[k] += cnt[x * i];
			}
		}
		for (int x = c, y = 1; x >= 1; --x) {
			if (cnt[x * i]) {
				int s = 0;
				for (int k : d[x]) {
					s += mu[k] * v[k];
				}
				while (s) {
					ans = std::max(ans, 1ll * x * y * i);
					for (int k : d[y]) {
						v[k] -= cnt[y * i];
						if (x % k == 0) {
							s -= mu[k] * cnt[y * i];
						}
					}
					++y;
				}
			}
		}
	}
	std::cout << ans << "\n";
}