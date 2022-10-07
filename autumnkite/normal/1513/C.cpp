#include <bits/stdc++.h>

const int N = 200000, P = 1000000007;

int f[N + 1];

int calc(int m) {
	return m < 0 ? 1 : f[m];
}

void init() {
	for (int i = 0; i <= N; ++i) {
		f[i] = (calc(i - 9) + calc(i - 10)) % P;
	}
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	int ans = 0;
	while (n) {
		ans = (ans + calc(m - 10 + n % 10)) % P;
		n /= 10;
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init();
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}