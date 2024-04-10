#include <iostream>

int main() {
	int w, h, k;
	std::cin >> w >> h >> k;
	int ans = 0;
	for(int i = 1; i <= k; i++) {
		ans +=	2*((w-4*(i-1))+(h-4*(i-1)))-4;
	}
	std::cout << ans << std::endl;
	
	return 0;
}