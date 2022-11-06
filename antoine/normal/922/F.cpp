#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

vector<int> knapsack(vector<pair<int, int>> &v, int sum) {
	map<int, vector<int>> mp;
	for (auto &&x : v)
	if(x.second && x.second <= sum && mp[x.second].size() < sum / x.second)
		mp[x.second].push_back(x.first);
	v.clear();
	for (auto &&x : mp)
		for (auto &&y : x.second)
			v.emplace_back(y, x.first);
	vector<vector<char>> dp(v.size() + 1, vector<char>(sum + 1, 0));
	dp[v.size()][0] = 1;
	for (int i = v.size() - 1; i >= 0; --i)
		for (int j = 0; j <= sum; ++j)
			dp[i][j] = !j || dp[i + 1][j] || (v[i].second <= j && dp[i + 1][j - v[i].second]);
	if (!dp[0][sum]) {
		cout << "error";
		exit(0);
	}
	vector<int> res;
	for (int i = 0; sum; ++i)
		if (!dp[i + 1][sum]) {
			sum -= v[i].second;
			res.push_back(v[i].first);
		}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		for (int j = i << 1; j <= n; j += i)
			++dp[j];


	int m = 0;
	int sum = 0;
	while (m <= n && sum < k)
		sum += dp[m++];
	--m;
	if (sum < k) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	vector<pair<int, int>> v;
	for (int i = m / 2 + 1; i <= m; ++i)
		v.emplace_back(i, dp[i] + m / i - 1);
	auto res = knapsack(v, sum - k);
	cout << m - res.size() << '\n';
	for (int i = 1; i <= m; ++i)
		if (!binary_search(res.begin(), res.end(), i))
			cout << i << ' ';
	return 0;
}