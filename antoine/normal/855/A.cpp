#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <array>
#include <queue>
#include <functional>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);


	int n;
	std::cin >> n;
	std::unordered_set<std::string> mp;
	for (int i = 0; i < n; ++i) {
		std::string s;
		std::cin >> s;
		if (mp.count(s))
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
		mp.insert(s);
	}
	return 0;
}