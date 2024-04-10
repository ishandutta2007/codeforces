#include <bits/stdc++.h>

void solve() {
	long long n;
	std::cin >> n;
	if (n % 2050 != 0) {
		std::cout << -1 << "\n";
	} else {
		n /= 2050;
		int ans = 0;
		while (n) {
			ans += n % 10;
			n /= 10;
		}
		std::cout << ans << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}