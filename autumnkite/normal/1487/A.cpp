#include <bits/stdc++.h>

int n;
int a[105];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	int mn = *std::min_element(a + 1, a + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += a[i] > mn;
	}
	std::cout << ans << "\n";
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