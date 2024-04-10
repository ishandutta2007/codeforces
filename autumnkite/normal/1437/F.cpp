#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int &v : a) {
		std::cin >> v;
	}
	std::sort(a.begin(), a.end());

	std::vector<int> inv(n + 1);
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	}

	std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
	f[n][0] = 1;
	for (int i = n; i >= 1; --i) {
		int t = i - 1;
		while (t >= 1 && a[t - 1] * 2 > a[i - 1]) {
			--t;
		}
		for (int j = 1; j <= n; ++j) {
			f[i - 1][j - 1] = (f[i - 1][j - 1] + 1ll * f[i][j] * j) % P;
		}
		int now = 1;
		for (int j = 1; j < i - t; ++j) {
			now = 1ll * now * j % P;
		}
		int sum = 0;
		for (int j = i - t - 1; j <= n; ++j) {
			if (j >= i - t) {
				now = 1ll * now * j % P * inv[j - (i - t) + 1] % P;
			}
			sum = (sum + 1ll * f[i][j] * now) % P;
			f[t][j - (i - t) + 1] = (f[t][j - (i - t) + 1] + sum) % P;
		}
	}
	std::cout << f[0][0] << "\n";
}