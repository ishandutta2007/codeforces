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
	std::cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); ++i)
		for (int j = i + 1; j < s.size(); ++j)
			for (int k = j + 1; k < s.size(); ++k)
				if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
					++ans;
	std::cout << ans;
	return 0;
}