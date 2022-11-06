#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::string s;
	int n, m;
	std::cin >> n >> m >> s;
	for (; m > 0; --m) {
		int l, r;
		char c, d;
		std::cin >> l >> r >> c >> d;
		for (; l <= r; ++l)
			if (s[l-1] == c)
				s[l-1] = d;
	}
	std::cout << s;
	return 0;
}