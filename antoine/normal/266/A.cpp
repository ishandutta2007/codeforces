
#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int count = 0;
	for(int i = 1; i < s.length(); ++i)
		if(s[i] == s[i-1])
			++count;
		std::cout << count;
	return 0;
}