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

	int seatt = 0;
	int sf = 0;
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	for (int i = 0; i + 1 < n; ++i)
		if (s[i] != s[i + 1]) {
			if (s[i + 1] == 'F')
				++sf;
			else
				++seatt;
		}
	std::cout << (seatt < sf ? "YES" : "NO") << '\n';
	return 0;
}