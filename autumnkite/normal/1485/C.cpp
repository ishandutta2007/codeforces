#include <bits/stdc++.h>

int x, y;

void solve() {
	std::cin >> x >> y;
	long long ans = 0;
	for (int i = 1; i * i <= x && i <= y; ++i) {
		ans += i * i / (i + 1);
		ans -= x / (i + 1);
	}
	for (int l = 2, r; l <= y + 1 && l <= x; l = r + 1) {
		r = std::min(y + 1, x / (x / l));
		ans += 1ll * (r - l + 1) * (x / l);
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}