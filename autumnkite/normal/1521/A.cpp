#include <bits/stdc++.h>

void solve() {
	int A, B;
	std::cin >> A >> B;
	if (B == 1) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		std::cout << 1ll * A * (B - 1) << " " << 1ll * A * (B + 1) << " " << 2ll * A * B << "\n";
	}
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