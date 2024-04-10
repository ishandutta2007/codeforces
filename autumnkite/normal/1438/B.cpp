#include <bits/stdc++.h>

const int N = 1005;

int n;
int a[N];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + 1 + n);
	if (std::unique(a + 1, a + 1 + n) - a - 1 == n) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}