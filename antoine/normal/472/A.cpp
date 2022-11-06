#include <iostream>
#include <algorithm>
#include <cstring>

bool comp[1000001];


int main() {
	int n;
	std::cin >> n;
	if (!(n & 1)) {
		std::cout << 4 << " " << (n - 4);
		return 0;
	}
	for (int i = 2; i*i <= n; ++i)
		if (!comp[i]) {
			for (int j = i*i; j <= n; j += i)
				comp[j] = true;
		}
	for(int i = 4;; ++i)
		if (comp[i] && comp[n - i]) {
			std::cout << i << " " << (n - i);
			break;
		}
	return 0;
}