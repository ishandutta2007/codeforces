#include <bits/stdc++.h>

const int N = 200005;

int n, k, a[N];

void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n * k; ++i) {
		std::cin >> a[i];
	}
	long long ans = 0;
	for (int i = 1; i <= k; ++i) {
		ans += a[n * k - (n / 2 + 1) * i + 1];
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