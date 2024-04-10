#include <bits/stdc++.h>

const int N = 100005;

int n, a[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n;
	int mn = 0x3f3f3f3f;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		mn = std::min(mn, a[i] / n);
	}
	for (int i = 0; i < n; ++i) {
		a[i] -= mn * n;
	}
	for (int i = 0; i < n; ++i) {
		if (std::max(a[i] - i, 0) == 0) {
			std::cout << i + 1 << "\n";
			return 0;
		}
		a[i] = std::max(a[i] - n, 0);
	}
	for (int i = 0; i < n; ++i) {
		if (std::max(a[i] - i, 0) == 0) {
			std::cout << i + 1 << "\n";
			return 0;
		}
	}
}