#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, p, x;
	std::cin >> n >> p >> x;
	std::map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		v = (1ll * v * v % p * v % p * v + 1ll * (p - x) * v) % p;
		++cnt[v];
	}
	long long ans = 0;
	for (auto [v, c] : cnt) {
		ans += 1ll * c * (c - 1) / 2;
	}
	std::cout << ans << "\n";
}