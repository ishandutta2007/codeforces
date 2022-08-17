#include <iostream>
#include <map>

signed main() {
	int n;
	std::cin >> n;

	std::map<std::string, int> m;
	for(int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		if(m[s])
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
		m[s] = 1;
	}

	return 0;
}