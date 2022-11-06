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

ll grid[2][(int)1e6 + 2];
ll sum[2][(int)1e6 + 2];
ll acc[2][(int)1e6 + 2];
ll rev[2][(int)1e6 + 2];
ll dp[(int)1e6 + 2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int r = 0; r < 2; ++r) {
		for (int i = 1; i <= n; ++i)
			cin >> grid[r][i];

		partial_sum(grid[r], grid[r] + n + 1, sum[r]);

		for (int i = 0; i <= n; ++i)
			acc[r][i] = acc[r][i - 1] + grid[r][i] * i;

		for (int i = n; i >= 1; --i)
			rev[r][i] = rev[r][i + 1] + grid[r][i] * (n - i);
	}

	for (int i = n; i >= 1; --i) {
		int r = (i & 1) ^ 1;
		ll t = (i - 1) << 1;
		assert(t + 2 * (n  + 1- i) == 2 * n);
		dp[i] = t * grid[r][i] + (t + 1) * grid[r ^ 1][i] + dp[i + 1];
		dp[i] = max(dp[i], (acc[r][n] - acc[r][i - 1]) + (sum[r][n] - sum[r][i - 1]) * (t - i) +
			(rev[r ^ 1][i] - rev[r ^ 1][n + 1]) + (sum[r ^ 1][n] - sum[r ^ 1][i - 1]) * (t + n + 1 - i)
		);
	}
	cout << dp[1];
	return 0;
}