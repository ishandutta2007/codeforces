#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	long long r;
	std::cin >> r;
	if (r < 5 || !(r & 1)) {
		std::cout << "NO\n";
	} else {
		std::cout << 1 << " " << (r - 3) / 2 << "\n";
	}
}