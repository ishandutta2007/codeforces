#include <bits/stdc++.h>

int work(std::vector<int> id) {
	std::cout << "next ";
	for (int v : id) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
	int x;
	std::cin >> x;
	for (int i = 0; i < x; ++i) {
		std::string tmp;
		std::cin >> tmp;
	}
	return x;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	while ((work({0, 1}), work({1})) == 3) {
		;
	}
	while (work({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) == 2) {
		;
	}
	std::cout << "done" << std::endl;
}