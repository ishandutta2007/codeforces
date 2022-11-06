#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <array>
#include <set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long long a, b;
	std::cin >> a >> b;
	if (a == 0) a = 1;
	if (b == 0) b = 1;
	long long ans = 1;
	int max_it = 100;
	while (b > a && --max_it > 0) {
		ans *= b%10;
		ans %= 10;
		--b;
	}
	std::cout << ans << '\n';
	return 0;
}