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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;


int  main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	const int n = s.size();
	vector<vector<int>> dp(n, vector<int>(3, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 3; ++j) {
			int &res = dp[i][j];
			if (j) res = min(res, dp[i][0]);
			res = max(res, (i ? dp[i - 1][0] : 0) + ((j + s[i] - '0') % 3 == 0));
			res = max(res, (i ? dp[i - 1][(j + s[i] - '0') % 3] : 0));
		}
	cout << dp[n - 1][0];
	return 0;
}