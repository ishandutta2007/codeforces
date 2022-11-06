#include <iostream>
#include <algorithm>
#include <cstring>

int no[100003];

int main() {
	int n;
	std::cin >> n;
	std::memset(no, 0, sizeof no);
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		++no[x];
	}
	for (int i = 1; i < 100003; ++i)
		no[i] += no[i - 1];

	int q;
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		int m;
		std::cin >> m;
		m = std::min(m, 100002);
		std::cout << no[m] << "\n";
	}
	return 0;
}