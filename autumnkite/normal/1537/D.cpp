#include <bits/stdc++.h>

void solve() {
	int x;
	std::cin >> x;
	int c = 0;
	while (x % 2 == 0) {
		x /= 2;
		++c;
	}
	std::cout << (c && (x > 1 || !(c & 1)) ? "Alice" : "Bob") << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}