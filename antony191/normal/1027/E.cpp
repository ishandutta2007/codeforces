#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9, mod = 998244353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	if (k == 1) return cout << 0, 0;
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	for (int t = 1; t <= n; ++t) {
		dp[t - 1][0] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = i - 1; i - j <= t && j >= 0; --j) {
				dp[t - 1][i] += dp[t - 1][j];
				if (dp[t - 1][i] >= mod) dp[t - 1][i] -= mod;
			}
			if (i < t) dp[t - 1][i]++;
			if (dp[t - 1][i] >= mod) dp[t - 1][i] -= mod;
		}
	}
	k--;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		int j = min(k / i, n);
		if (j == 0) break;
		if (i == 1)
			ans = (ans + dp[0][n - 1] * 1ll * dp[j - 1][n - 1]) % mod;
		else
			ans = (ans + (dp[i - 1][n - 1] - dp[i - 2][n - 1]) * 1ll * dp[j - 1][n - 1]) % mod;
	}
	ans = (ans % mod % mod) % mod;
	ans = (ans * 2) % mod;
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}