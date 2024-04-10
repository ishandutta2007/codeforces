#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int n;
int s[2000];

void f() {
	std::cin >> n;
	std::set<int> S;
	int g = -1;
	for (int i = 0; i < n; ++i) {
		std::cin >> s[i];
		S.insert(s[i]);
		if (g == -1)
			g = s[i];
		else
			g = gcd(g, s[i]);
	}
	if (!S.count(g)) {
		std::cout << -1;
		return;
	}
	std::cout << (2 * n) << '\n';
	for (int i = 0; i < n; ++i) {
		if (i)
			std::cout << ' ';
		std::cout << s[i] << ' ' << g;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	f();
	return 0;
}