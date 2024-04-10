#include <bits/stdc++.h>

const int N = 105;

int n, k;
int a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int x;
		std::cin >> x;
		++a[x];
	}
	int t = 0;
	for (int i = 1; i <= 100; ++i) {
		t = std::max(t, (a[i] + k - 1) / k);
	}
	int ans = 0;
	for (int i = 1; i <= 100; ++i) {
		if (a[i]) {
			ans += t * k;
		}
	}
	std::cout << ans - n << "\n";
}