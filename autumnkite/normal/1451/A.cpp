#include <bits/stdc++.h>

int n;

void solve() {
	std::cin >> n;
	if (n == 1) {
		std::cout << 0 << "\n";
	} else if (n == 2) {
		std::cout << 1 << "\n";
	} else if (n == 3 || !(n & 1)) {
		std::cout << 2 << "\n";
	} else {
		std::cout << 3 << "\n";
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