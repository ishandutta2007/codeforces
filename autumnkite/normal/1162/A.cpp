#include <bits/stdc++.h>

const int N = 55;

int n, h, m, a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> h >> m;
	for (int i = 1; i <= n; ++i) {
		a[i] = h;
	}
	for (int i = 1; i <= m; ++i) {
		int l, r, x;
		std::cin >> l >> r >> x;
		for (int j = l; j <= r; ++j) {
			a[j] = std::min(a[j], x);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += a[i] * a[i];
	}
	std::cout << ans << "\n";
}