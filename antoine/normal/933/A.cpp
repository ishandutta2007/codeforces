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
#include <stack>

using namespace std;
typedef long long ll;


vector<int> f(const vector<int> &a) {
	vector<array<int, 2>> dp(a.size());
	vector<int> res(dp.size());
	for (int i = 0; i < dp.size(); ++i) {
		dp[i][0] = (a[i] == 0) + (i ? dp[i - 1][0] : 0);
		dp[i][1] = (a[i] == 1) + (i ? max(dp[i - 1][0], dp[i - 1][1]) : 0);
		res[i] = max(dp[i][0], dp[i][1]);
	}
	return res;
}

vector<int> f(vector<int> a, int j) {
	while (a.size() > j + 1)
		a.pop_back();
	reverse(a.begin(), a.end());
	return f(a);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	vector<array<int, 2>> dp(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = (a[i] == j) + (i ? dp[i - 1][j] : 0);
		}
	}
	int ans = max(dp.back()[0], dp.back()[1]);
	for (int i = 0; i < n; ++i)
		ans = max(ans, dp[i][0] + dp.back()[1] - dp[i][1]);

	for (int j = 0; j < n; ++j) {
		auto res = f(a, j);
		for (int i = 0; i < j; ++i) {
			ans = max(ans, res[j - i] + (i ? dp[i - 1][0] : 0) + dp.back()[1] - dp[j][1]);
		}
	}
	cout << ans;
	return 0;
}