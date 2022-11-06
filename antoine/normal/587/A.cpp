#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <unordered_set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	std::cin >> n;
	std::unordered_set<int> s;
	s.reserve(2 * n);
	for (; n > 0; --n) {
		int w;
		std::cin >> w;
		for (;;) {
			auto it = s.find(w);
			if (it == s.end())
				break;
			s.erase(it);
			++w;
		}
		s.insert(w);
	}
	std::cout << s.size();
	return 0;
}