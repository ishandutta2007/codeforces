#include <iostream>
#include <string>
#include <algorithm>

int dp[100009];

int main() {
	std::string s;
	std::cin >> s;
	int m;
	std::cin >> m;
	dp[s.size()] = 0;
	for (int i = s.size() - 1; i > 0; --i) {
		dp[i] = dp[i + 1] + (s[i] == s[i - 1] ? 1 : 0);
	}

	for (; m > 0; --m) {
		int l, r;
		std::cin >> l >> r;
		std::cout << dp[l] - dp[r] << "\n";
	}
}