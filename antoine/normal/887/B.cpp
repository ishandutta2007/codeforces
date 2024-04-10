#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>

std::set<int> all;

std::vector<std::set<int>> values;


void bt(int i, int curr) {
	if (i >= values.size())
		all.insert(curr);
	else
		for (auto &&x : values[i]) {
			bt(i + 1, curr * 10 + x);
		}
}

void f(int i) {
	if (values[i].size() == 1 && *(values[i].begin()) == 0)
		return;
	bt(i, 0);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	values.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 6; ++j) {
			int x;
			std::cin >> x;
			values[i].insert(x);
		}
	}
	std::sort(values.begin(), values.end());
	do {
		for (int i = 0; i < n; ++i)
			f(i);
	} while (std::next_permutation(values.begin(), values.end()));

	if (all.size() == 0)
		std::cout << 0;
	else {
		for(int i = 1;; ++i)
			if (!all.count(i)) {
				std::cout << (i - 1);
				return 0;
			}
	}
	return 0;
}