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

	int n, q;
	cin >> n >> q;
	vector<vector<int>> add(n), undo(n);
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		add[--l].push_back(x);
		undo[--r].push_back(x);
	}
	
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	vector<bool> ans(n + 1, false);
	for (int i = 0; i < n; ++i) {
		for(auto &&x : add[i])
			for (int j = n; j >= x; --j) {
				dp[j] += dp[j - x];
				dp[j] ? ans[j] = true : 0;
			}
		for(auto &&x : undo[i])
			for (int j = x; j <= n; ++j)
				dp[j] -= dp[j - x];
	}

	cout << count(ans.begin(), ans.end(), 1) << '\n';
	for (int i = 1; i <= n; ++i)
		if (ans[i])
			cout << i << ' ';
	return 0;
}