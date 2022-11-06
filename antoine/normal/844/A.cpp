#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string s;
	int k;
	std::cin >> s >> k;
	if (k > s.length()) {
		std::cout << "impossible";
		return 0;
	}
	std::set<char> sset;
	for (char c : s)
		sset.insert(c);
	std::cout << std::max(0, k - (int)sset.size()) << '\n';
	return 0;
}