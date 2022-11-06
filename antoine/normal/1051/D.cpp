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


const int mod = 998244353;

ll dp[2][2001][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, K;
	cin >> N >> K;

	for (int k = 0; k <= K; ++k)
		for (int d = 0; d < 2; ++d)
			dp[0][k][d] = k == 0;

	for (int i = 1; i < N; ++i)
		for (int k = 0; k <= K; ++k) {
			dp[i & 1][k][1] = dp[~i & 1][k][1] + (k < 2 ? 0 : dp[~i & 1][k - 2][1]) + 2 * dp[~i & 1][k][0];
			dp[i & 1][k][0] = dp[~i & 1][k][0] + (k < 1 ? 0 : dp[~i & 1][k - 1][0]) + 2 * (k < 1 ? 0 : dp[~i & 1][k - 1][1]);


			for (int d = 0; d < 2; ++d)
				dp[i & 1][k][d] %= mod;
		}

	ll res = 2 * dp[~N & 1][K - 1][0] + 2 * (K < 2 ? 0 : dp[~N & 1][K - 2][1]);
	cout << res % mod << '\n';
	return 0;
}