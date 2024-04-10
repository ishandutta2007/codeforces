#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <unordered_set>

char str[200001];
bool dp[100000];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> str;
	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int a;
		std::cin >> a;
		--a;
		dp[a] = !dp[a];
	}
	bool rev = false;
	int len = 1;
	while (str[len])
		++len;
	int halfLen = len >> 1;
	for (int i = 0; i < halfLen; ++i) {
		rev ^= dp[i];
		if (rev)
			std::swap(str[i], str[len - 1 - i]);
	}
	std::cout << str;
	return 0;
}