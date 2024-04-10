#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> dp(100010);
	dp[0] = 2;
	dp[1] = 2;
	for (int i = 2; i < dp.size(); i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	int res = (dp[N] + dp[M] - 2 + MOD) % MOD;
	cout << res << endl;
}