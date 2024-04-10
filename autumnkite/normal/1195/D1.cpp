#include <bits/stdc++.h>

const int N = 100005, P = 998244353;

int n;
int a[N], len, cnt[11];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		int x = a[i], len = 0;
		while (x) {
			x /= 10;
			++len;
		}
		++cnt[len];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int x = a[i], pw = 1, v = 0;
		for (int j = 1; j <= 10; ++j) {
			v = (v + 1ll * x % 10 * pw) % P;
			x /= 10;
			pw = 100ll * pw % P;
			ans = (ans + (2ll * x * pw + 11ll * v) % P * cnt[j]) % P;
		}
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
}