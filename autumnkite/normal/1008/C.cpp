#include <bits/stdc++.h>

const int N = 100005;

int n, a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + 1 + n);
	int now = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		++now;
		if (i == n || a[i] != a[i + 1]) {
			ans = std::max(ans, now);
			now = 0;
		}
	}
	std::cout << n - ans << "\n";
}