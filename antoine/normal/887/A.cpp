#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>


std::string s;

bool f() {
	int i = s.length() - 1;
	int count = 0;
	while (i >= 0 && count < 6) {
		count += s[i--] == '0';
	}
	if (count != 6)
		return false;
	for (; i >= 0; --i)
		if (s[i] == '1')
			return true;
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> s;
	std::cout << (f() ? "yes" : "no");

	return 0;
}