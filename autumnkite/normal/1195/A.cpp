#include <bits/stdc++.h>

const int N = 1005;

int n, k, a[N], c[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		++c[a[i]];
	}
	int ans = 0, cnt = 0;
	for (int i = 1; i <= k; ++i) {
		ans += c[i] / 2;
		cnt += c[i] % 2;
	}
	std::cout << ans * 2 + (cnt + 1) / 2 << "\n";
}