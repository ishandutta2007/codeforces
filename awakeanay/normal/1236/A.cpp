#include <iostream>

int main() {
	int t;
	std::cin >> t;

	while(t--) {
		int a, b, c;
		std::cin >> a >> b >> c;

		int ans = 0;

		int x = std::min(b, c/2);
		c -= 2*x;
		b -= x;
		ans += 3*x;

		int y = std::min(a, b/2);
		ans += 3*y;

		std::cout << ans << std::endl;
	}

	return 0;
}