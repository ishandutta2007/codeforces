#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

int n;
int a[2000];
int dp[2000];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	int best = -1;
	
	for (int i = 0; i < n; ++i) {
		int g = a[i];
		int j = i + 1;
		for (dp[i] = 0; g != 1 && j < n; ++dp[i])
			g = gcd(g, a[j++]);

		if (g == 1 && (best == -1 || dp[i] < dp[best]))
			best = i;
	}

	if (best == -1) {
		std::cout << -1;
		return 0;
	}
	int ans = 0;
	int i = best;
	while (a[i] != 1) {
		a[i + 1] = gcd(a[i], a[i + 1]);
		++i;
		++ans;
	}
	for (int i = 0; i < n; ++i)
		if (a[i] != 1)
			++ans;
	std::cout << ans << '\n';
	
	return 0;
}