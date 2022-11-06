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

	int n, m, q;
	string s, t;
	cin >> n >> m >> q >> s >> t;
	assert(s.size() == n && t.size() == m);
	vector<int> dp(n, 0);
	for (int i = 0; i < n; ++i)
		dp[i] = s.substr(i, m) == t;
	partial_sum(dp.begin(), dp.end(), dp.begin());
	dp.insert(dp.begin(), 0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		r -= m - 1;
		cout << (l <= r ? dp[r] - dp[l - 1] : 0) << '\n';
	}
	return 0;
}