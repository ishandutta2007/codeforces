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
int MOD = 998244353;
int solve(int N, int M) {
	M++;
	vector<vector<int> > dp(N + 1, vector<int>(M, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < M; j++) {
			dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
		}
		for (int j = 0; j < M; j++) {
			dp[i][1] = (dp[i][1] + dp[i - 1][j]) % MOD;
		}
	}
	int res = 0;
	for (int i = 0; i < M; i++) {
		res = (res + dp[N][i]) % MOD;
	}
	return res;
}
map<int, int> mp;
int d(int N, int K) {
	K = min(K, N);
	if (mp.count(K) == 0) {
		mp[K] = solve(N, K);
	}
	return mp[K];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	K--;
	mp[0] = 0;
	//cout << d(N, N) << endl;
	int res = 0;
	for (int i = 1; i <= N; i++) {
		int j = K / i;
		int a = (MOD + d(N, i) - d(N, i - 1)) % MOD;
		int b = d(N, j);
		//cerr << i << " " << a << " " << b << endl;
		res = (res + ((a*b) % MOD)) % MOD;
	}

	cout << ((res * (MOD + 1) / 2) % MOD) << endl;
}