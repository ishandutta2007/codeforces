#include <bits/stdc++.h>

long long n;

void solve() {
	std::cin >> n;
	while (n % 2 == 0) {
		n /= 2;
	}
	if (n > 1) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
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