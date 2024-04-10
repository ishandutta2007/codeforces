#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <map>

int main() {
	int n, m;
	std::cin >> n >> m;
	int count = 0;
	for (; n < m; ++count) {
		if (m & 1)
			++m;
		else
			m >>= 1;
	}
	std::cout << count + n - m;
	return 0;
}