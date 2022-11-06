#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int bf(const int &n, const vector<int> &a, int &p, const int &k) {
	int ans = 0;
	while (p <= n) {
		++ans;
		p += a[p] + k;
	}
	return ans;
}

int f(const int &n, const vector<int> &a, const int &p, const int &k, vector<vector<int>> &dp) {
	if (p > n)
		return 0;
	if (dp[p][k] != -1)
		return dp[p][k];
	return dp[p][k] = 1 + f(n, a, p + a[p] + k, k, dp);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	int limit = sqrt(n) / 2;
	vector<vector<int>> dp(n + 1, vector<int>(limit, -1));

	int q;
	cin >> q;
	for (; q > 0; --q) {
		int p, k;
		cin >> p >> k;
		if (k < limit)
			cout << f(n, a, p, k, dp) << '\n';
		else
			cout << bf(n, a, p, k) << '\n';
	}
	return 0;
}