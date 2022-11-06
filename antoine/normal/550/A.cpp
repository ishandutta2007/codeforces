#include <iostream>
#include <string>
#include <algorithm>

std::string s;
bool f1() {
	for (int i = 0; i + 1 < s.size(); ++i)
		if (s[i] == 'A' && s[i + 1] == 'B') {
			for (i = i + 2; i + 1 < s.size(); ++i)
				if (s[i] == 'B' && s[i + 1] == 'A') {
					return true;
				}
			break;
		}
	return false;
}

bool f2() {
	for (int i = 0; i + 1 < s.size(); ++i)
		if (s[i] == 'B' && s[i + 1] == 'A') {
			for (i = i + 2; i + 1 < s.size(); ++i)
				if (s[i] == 'A' && s[i + 1] == 'B') {
					return true;
				}
			break;
		}
	return false;
}

int main() {
	std::cin >> s;
	if (f1() || f2())
		std::cout << "YES";
	else
		std::cout << "NO";
}