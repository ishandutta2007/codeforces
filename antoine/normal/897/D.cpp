#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

int a[100000];

int n, m, c;
void query(int p) {
	if (p <= c / 2) {
		for(int i = 1;; ++i)
			if (!a[i] || a[i] > p || i == n) {
				a[i] = p;
				std::cout << i << std::endl;
				break;
			}
	}
	else {
		for(int i = n;; --i)
			if (!a[i] || a[i] < p || i == 1) {
				a[i] = p;
				std::cout << i << std::endl;
				break;
			}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::memset(a, 0, sizeof a);

	std::cin >> n >> m >> c;

	for (; m > 0; --m) {
		int p;
		std::cin >> p;
		query(p);
	}
	return 0;
}