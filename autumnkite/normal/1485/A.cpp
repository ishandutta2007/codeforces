#include <bits/stdc++.h>

int a, b;

void solve() {
	std::cin >> a >> b;
	int ans = 35;
	for (int i = b == 1 ? 1 : 0; i <= ans; ++i) {
		int n = a, s = i;
		while (n) {
			n /= (b + i);
			++s;
		}
		ans = std::min(ans, s);
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