// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> c(n*k);
	for (int i = 0; i < c.size(); ++i)
		cin >> c[i];

	vector<int> f(n);
	for (int i = 0; i < n; ++i)
		cin >> f[i];

	vector<int> h(k + 1, 0);
	for (int i = 1; i <= k; ++i)
		cin >> h[i];

	vector<vector<ll>> dp(n + 1, vector<ll>(n*k + 1, 0));
	for (int i = 1; i < dp.size(); ++i)
		for (int j = dp[0].size() - 1; j >= 0; --j) {
			for (int x = min(j, k); x >= 0; --x)
				dp[i][j] = max(dp[i][j], h[x] + (i ? dp[i - 1][j - x] : 0));
		}

	map<int, int> occ; // card occ.
	for (auto &&x : c)
		++occ[x];

	map<int, int> mp; // card - person
	for (auto &&x : f)
		mp[x]++;

	ll ans = 0;
	for (auto &&x : mp) {
		ans += dp[x.second][occ[x.first]];
		// cout << x.second << ' ' << occ[x.first]  << " --> " << dp[x.second][occ[x.first]] << '\n';
	}
	cout << ans;
	return 0;
}