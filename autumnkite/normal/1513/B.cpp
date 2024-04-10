#include <bits/stdc++.h>

const int P = 1000000007;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int and_sum = a[0];
	for (int i = 0; i < n; ++i) {
		and_sum &= a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		a[i] ^= and_sum;
		cnt += a[i] == 0;
	}
	int ans = 1ll * cnt * (cnt - 1) % P;
	for (int i = 1; i <= n - 2; ++i) {
		ans = 1ll * ans * i % P;
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