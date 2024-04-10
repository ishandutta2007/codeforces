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
	int m = std::unique(a + 1, a + 1 + n) - a - 1;
	for (int i = 1; i <= m; ++i) {
		if (a[i] == 0) {
			std::cout << m - 1 << "\n";
			return 0;
		}
	}
	std::cout << m << "\n";
}