/*input
3 5 6 11
1 2 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, b, mod;
	cin >> n >> m >> b >> mod;

	vector<vector<int>> dp(m + 1, vector<int>(b + 1, 0));
	dp[0][0] = 1;
	while (n--) {
		int x;
		cin >> x;

		for (int i = 1; i <= m; ++i) {
			for (int j = x; j <= b; ++j) {
				dp[i][j] += dp[i - 1][j - x];
				dp[i][j] -= (dp[i][j] >= mod ? mod : 0);
			}
		}
	}

	cout << accumulate(dp[m].begin(), dp[m].end(), 0ll) % mod << endl;
}