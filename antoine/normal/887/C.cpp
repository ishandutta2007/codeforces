#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>

int a[25];

bool squareSameClr(int i) {
	return a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3];
}

bool check(const std::vector<int> c, const std::vector<int> b) {
	for (int shift : { (int)c.size() - 2, 2 }) {
		bool succ = true;
		for(int i = 0; i < c.size(); ++i)
			if (a[c[(i + shift) % 8]] != a[b[i]]) {
				succ = false;
				break;
			}
		if (succ)
			return true;
	}
	return false;
}

bool feasible() {
	if (squareSameClr(1) && squareSameClr(9)) {
		return check({ 13, 14, 5, 6, 17, 18, 21, 22 },
		{15, 16, 7, 8, 19, 20, 23, 24});
	}
	if (squareSameClr(13) && squareSameClr(17)) {
		return check(
		{24, 22, 1, 3, 5, 7, 9, 11},
		{23, 21, 2, 4, 6, 8, 10, 12}
		);
	}

	if (squareSameClr(5) && squareSameClr(21)) {
		return check(
		{3, 4, 17, 19, 10, 9, 16, 14},
		{1, 2, 18, 20, 12, 11, 15, 13}
		);
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	for (int i = 1; i <= 24; ++i)
		std::cin >> a[i];
	std::cout << (feasible() ? "YES" : "NO");
	return 0;
}