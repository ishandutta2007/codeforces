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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		cin >> dp[i][i];
	for (int diff = 1; diff < n; ++diff)
		for (int i = 0; i + diff < n; ++i)
			dp[i][i + diff] = dp[i][i + diff - 1] ^ dp[i + 1][i + diff];
	for (int diff = 1; diff < n; ++diff)
		for (int i = 0; i + diff < n; ++i)
			dp[i][i + diff] = max(dp[i][i+diff], max(dp[i][i + diff - 1], dp[i + 1][i + diff]));
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << dp[--l][--r] << '\n';
	}


	return 0;
}