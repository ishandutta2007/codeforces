#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

int n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n;
	std::multiset<int> all = { 0 };
	for (int i = 1; i <= n; ++i) {
		int a;
		std::cin >> a;
		if (all.count(a))
			all.erase(all.find(a));
		all.insert(i);
	}
	std::cout << all.size();
	return 0;
}