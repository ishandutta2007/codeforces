#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

std::string str;
int dp[3002];
int choice[3002];
bool isCons[3002];

int f(int i) {
	if (i >= str.size()) return 0;
	if (dp[i] != -1) return dp[i];
	dp[i] = 1 + f(i + 1);
	choice[i] = i + 1;
	std::set<int> consonents;
	int consCount = 0;
	for (int j = i; j < str.size(); ++j) {
		if (isCons[j]) {
			consCount++;
			consonents.insert(str[j]);
			if (consCount >= 3 && consonents.size() >= 2)
				break;
		}
		else {
			consCount = 0;
			consonents.clear();
		}
		if (1 + dp[j + 1] < dp[i]) {
			dp[i] = 1 + dp[j + 1];
			choice[i] = j + 1;
		}
	}
	return dp[i];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::memset(dp, -1, sizeof dp);

	std::cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		char c = str[i];
		isCons[i] = c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
	}

	for (int i = str.size() - 1; i >= 0; --i)
		f(i);

	int i = 0;
	while (i < str.size()) {
		if (i != 0)
			std::cout << ' ';
		std::cout << str.substr(i, choice[i] - i);
		i = choice[i];
	}
	return 0;
}