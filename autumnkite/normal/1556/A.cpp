#include <bits/stdc++.h>

void solve() {
    int a, b;
    std::cin >> a >> b;
    if ((a & 1) ^ (b & 1)) {
        std::cout << -1 << "\n";
    } else if (a == b) {
        std::cout << (a > 0) << "\n";
    } else {
        std::cout << 2 << "\n";
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