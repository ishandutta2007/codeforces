#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector <int> m;

void min(int l, int s) {
	if (l == 1) m.push_back(s);
	else {
		int last = std::min(s - 1, 9);
		m.push_back(last);
		min(l - 1, s - last);
	}
}

void max(int l, int s) {
	for (; l > 0; --l) {
		int digit = std::min(s, 9);
		std::cout << digit;
		s -= digit;
	}
}

int main() {
	int l, s;
	std::cin >> l >> s;
	if (s == 0 && l == 1) {
		std::cout << "0 0";
		return 0;
	}
	if (s < 1 || l*9 < s) {
		std::cout << "-1 -1";
		return 0;
	}

	min(l, s);
	for (auto x = m.rbegin(); x != m.rend(); ++x)
		std::cout << *x;
	std::cout << " ";
	max(l, s);
	return 0;

}