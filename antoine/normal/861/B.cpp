#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

std::vector<std::pair<int, int>> memo; // flat, floor

int getExpFloor(int flatNumber, int fpf) {
	int expFloor = 1;
	while (flatNumber > fpf) {
		flatNumber -= fpf;
		++expFloor;
	}
	return expFloor;
}

bool possible(int fpf) {
	for (int i = 0; i < memo.size(); ++i)
		if (getExpFloor(memo[i].first, fpf) != memo[i].second)
			return false;
	return true;
}

int f() {
	int n, m;
	std::cin >> n >> m;
	memo.resize(m);
	for (int i = 0; i < m; ++i)
		std::cin >> memo[i].first >> memo[i].second;
	for (auto &&x : memo)
		if (x.first == n)
			return x.second;
	std::sort(memo.begin(), memo.end());
	std::set<int> possibilities;

	for (int fpf = 1; fpf <= 151; ++fpf) {
		if (possible(fpf))
			possibilities.insert(getExpFloor(n, fpf));
	}

	return possibilities.size() == 1 ? (*possibilities.begin()) : -1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << f();

	return 0;
}