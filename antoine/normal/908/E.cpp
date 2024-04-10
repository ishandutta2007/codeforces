#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int dp[1001][1001];
const int mod = 1e9 + 7;

int f(const int n, const int k = 0) {
	if (dp[n][k] != -1)
		return dp[n][k];
	if (n == 0)
		return 1;
	return dp[n][k] = ((long long)f(n - 1, k + 1) + (long long)k*(long long)f(n - 1, k)) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof dp);

	int m, n;
	cin >> m >> n;
	vector<set<int>> sets(m);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j)
			if (s[j] == '1')
				sets[j].insert(i);
	}

	map<set<int>, int> occ;
	for (auto &&x : sets)
		++occ[x];
	int ans = 1;
	for (auto &&x : occ)
		ans = ((long long)ans * (long long)f(x.second)) % mod;
	cout << ans;
	return 0;
}