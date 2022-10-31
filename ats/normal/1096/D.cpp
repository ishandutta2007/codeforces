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
	int N;
	cin >> N;
	string S;
	cin >> S;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int INF = (int)1 << 60;
	vector<vector<int> > dp(N + 1, vector<int>(5, INF));

	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		int k = -1;
		if (S[i] == 'h')k = 0;
		else if (S[i] == 'a')k = 1;
		else if (S[i] == 'r')k = 2;
		else if (S[i] == 'd')k = 3;
		for (int j = 0; j < 5; j++) {
			dp[i + 1][j] = dp[i][j];
		}
		if (k != -1) {
			dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[i][k]);
			dp[i + 1][k] = dp[i][k] + A[i];
		}

	}
	res = INF;
	for (int i = 0; i < 4; i++) {
		res = min(res, dp.back()[i]);
	}
	cout << res << endl;
}