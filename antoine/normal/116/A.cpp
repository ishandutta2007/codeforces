
#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
	int ans = 0;
	int n;
	std::cin >> n;
	int cap = 0;
	for(; n > 0; --n) {
		int a, b;
		std::cin >> a >> b;
		cap += b-a;
		ans = std::max(ans, cap);
	}
	std::cout << ans;
	return 0;
}