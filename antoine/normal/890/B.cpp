#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

int n;
int a[200005];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n;
	std::set<int> all;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		all.insert(a[i]);
	}
	std::set<int> curr;
	for (int i = n - 1; i >= 0; --i) {
		curr.insert(a[i]);
		if (curr.size() == all.size()) {
			std::cout << a[i];
			return 0;
		}
	}
	return 0;
}