#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>

bool f(std::string s) {
	int i = 0;
	int j = s.length() - 1;
	while (i < j) {
		if (s[i] != s[j])
			return false;
		++i; --j;
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int x;
	std::string s;

	std::cin >> x;
	s = std::to_string(x);

	for (int i = 0; i < 90; ++i) {
		if (f(s)) {
			std::cout << "YES";
			return 0;
		}
		s = "0" + s;
	}
	std::cout << "NO";

	return 0;
}