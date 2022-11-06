

#include <iostream>

bool chCount[26];

int main() {
	int n, m; std::cin >> n >> m;
	int max = -1;
	for(; n >= 1; --n) {
		int min = 1000000000 + 10;
		for(int i = 0; i < m; ++i) {
			int x;
			std::cin >> x;
			min = std::min(x, min);
		}
		max = std::max(min, max);
	}
	std::cout << max;
}