#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

int mod;
long long a[100000];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int k;
	std::cin >> k >> mod;
	long long sum = 0;

	for (int i = 1; k > 0; ++i) {
		--k;
		std::string s1 = std::to_string(i);
		std::string s2 = s1;
		std::reverse(s2.begin(), s2.end());
		sum += stoll(s1 + s2);
		sum %= mod;
	}
	std::cout << sum;
	return 0;
}