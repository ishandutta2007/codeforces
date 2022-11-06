#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

int L = 0;
char s[5001];

int dp[5000][5000];
int ans[5001] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> s;
	while (s[L])
		++L;

	// len 1
	for (int i = 0; s[i]; ++i)
		dp[i][i] = 1;
	
	// len 2
	for (int i = 0; i + 1 < L; ++i)
		dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 0;
	
	for (int l = 3; l <= L; ++l) {
		for (int i = 0, j = i + l - 1; j < L; ++i, ++j) {
			int &ans = dp[i][j];
			if (s[i] != s[j] || dp[i + 1][j - 1] == 0)
				ans = 0;
			else
				ans = dp[i][i + (l >> 1) - 1] + 1;
			//if (ans != 0)
				//std::cout << "dp is " << ans << " for [" << i << ", " << j << "]\n";
		}
	}
	for (int i = 0; s[i]; ++i)
		for (int j = i; s[j]; ++j)
			++ans[dp[i][j]];
	for (int i = L - 1; i >= 1; --i)
		ans[i] += ans[i + 1];
	for (int i = 1; i < L; ++i)
		std::cout << ans[i] << ' ';
	std::cout << ans[L] << '\n';
	return 0;
}