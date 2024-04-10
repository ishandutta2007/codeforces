#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> l(n), r(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> l[i] >> r[i];
		--l[i];
	}

	std::vector<int> mu(m + 1);
	mu[1] = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = i + i; j <= m; j += i) {
			mu[j] -= mu[i];
		}
	}

	int ans = 0;
	for (int d = 1; d <= m; ++d) {
		std::vector<int> f(m / d + 1);
		f[0] = 1;
		for (int i = 0; i < n; ++i) {
			int L = l[i] / d + 1, R = r[i] / d + 1;
			for (int j = 1; j <= m / d; ++j) {
				f[j] = (f[j] + f[j - 1]) % P;
			}
			std::vector<int> g(m / d + 1);
			for (int j = L; j <= m / d; ++j) {
				g[j] = f[j - L];
				if (j >= R) {
					g[j] = (g[j] + P - f[j - R]) % P;
				}
			}
			f.swap(g);
		}
		ans = (ans + std::accumulate(f.begin(), f.end(), 0ll) * mu[d]) % P;
	}
	std::cout << (ans + P) % P << "\n";
}