#include <bits/stdc++.h>

const int P = 998244353, Inv2 = (P + 1) / 2, Inv6 = (P + 1) / 6;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	++n;
	std::vector<int> f(n + 1);
	f[0] = 1;
	for (int i = 0; i < n; ++i) {
		f[i + 1] = (1ll * f[i] * (f[i] + 1) % P * Inv2 + 1) % P;
	}

	int ans = 0;
	for (int i = 2; i < n; ++i) {
		ans = (ans + 1ll * (f[i] - 2 * f[i - 1] + f[i - 2]) * (f[n - i] - f[n - i - 1])) % P;
	}
	ans = (ans + 2ll * f[n - 1] * (f[n - 1] + 1) % P * (f[n - 1] + 2) % P * Inv6) % P;
	ans = (ans - 2ll * f[n - 2] * (f[n - 2] + 1) % P * (f[n - 2] + 2) % P * Inv6) % P;
	ans = (ans - f[n - 1] + f[n - 2]) % P;
	std::cout << (ans + P) % P << "\n";
}