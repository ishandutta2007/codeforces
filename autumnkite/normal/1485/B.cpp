#include <bits/stdc++.h>

int n, q, k;
int a[100005];
long long sum[100005];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> q >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i + 1] - a[i - 1] - 2;
	}

	while (q--) {
		int l, r;
		std::cin >> l >> r;
		if (l == r) {
			std::cout << k - 1 << "\n";
			continue;
		}
		std::cout << sum[r - 1] - sum[l] + a[l + 1] - 2 + k - a[r - 1] - 1 << "\n";
	}
}