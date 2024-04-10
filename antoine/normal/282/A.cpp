
#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
	int T;
	std::cin >> T;
	std::string s;
	int count = 0;
	for(; T > 0; --T) {
		std::cin >> s;
		if(s[1] == '+')
			++count;
		else
			--count;
	}
	std::cout << count;
	return 0;
}