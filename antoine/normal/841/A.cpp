#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <string>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::string s;
	std::cin >> n >> k >> s;
	std::map<char, int> occ;
	for (char c : s)
		++occ[c];
	for(auto x : occ)
		if (x.second > k) {
			std::cout << "NO";
			return 0;
		}
	std::cout << "YES";
	return 0;
}