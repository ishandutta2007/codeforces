#include <iostream>
#include <string>

std::string s1, s2;

bool eq(int i1, int i2, int len) {
	for (int i = 0; i < len; ++i)
		if (s1[i1 + i] != s2[i2 + i]) {
			if (len & 1)
				return false;
			len >>= 1;
			return (eq(i1 + len, i2 + len, len) && eq(i1, i2, len))
				|| (eq(i1 + len, i2, len) && eq(i1, i2 + len, len));
		}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> s1 >> s2;
	if (s1.length() == s2.length() && eq(0, 0, s1.length()))
		std::cout << "YES";
	else
		std::cout << "NO";
	return 0;
}