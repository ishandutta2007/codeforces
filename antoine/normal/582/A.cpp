#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <map>

int gcd(int a, int b) {
	for (;;) {
		if (b == 0) return a;
		a %= b;
		if (a == 0) return b;
		b %= a;
	}
}

int n;
int result[500];
int resSz = 0;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	std::map<int, int, std::greater<int>> occ;
	for (int i = n*n; i > 0; --i) {
		int a;
		std::cin >> a;
		++occ[a];
	}
	
	while (!occ.empty()) {
		auto it = occ.begin();
		auto x = it->first;
		if (it->second == 1)
			occ.erase(it);
		else
			--it->second;
		for(int i = 0; i < resSz; ++i) {
			it = occ.find(gcd(x, result[i]));
			if (it->second == 2)
				occ.erase(it);
			else
				it->second -= 2;
		}
		result[resSz++] = x;
	}

	std::cout << result[0];
	for (int i = 1; i < resSz; ++i)
		std::cout << " " << result[i];
	return 0;
}