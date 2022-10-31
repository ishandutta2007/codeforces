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
int dp[105][2][2];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S[2];
	vector<int> A[2];
	for (int i = 0; i < 2; i++) {
		cin >> S[i];
	}
	A[0].clear();
	A[1].clear();
	A[0].push_back(1);
	A[1].push_back(1);
	for (int i = 0; i < S[0].size(); i++) {
		A[0].push_back((S[0][i] == 'X') ? 1 : 0);
		A[1].push_back((S[1][i] == 'X') ? 1 : 0);
	}
	int N = A[0].size();
	A[0].push_back(1);
	A[1].push_back(1);
	int INF = (int)1 << 60;
	for (int i = 0; i <= N; i++) {
		dp[i][0][0] = 0;
		dp[i][0][1] = 0;
		dp[i][1][0] = 0;
		dp[i][1][1] = 0;
		if (A[0][i] == 1) {
			dp[i][0][0] = -INF;
			dp[i][0][1] = -INF;
		}
		if (A[1][i] == 1) {
			dp[i][0][0] = -INF;
			dp[i][1][0] = -INF;
		}
	}

	for (int i = 0; i < N; i++) {
		if (A[0][i + 1] == 0) {
			dp[i + 1][1][A[1][i + 1]] = max(dp[i + 1][1][A[1][i + 1]], dp[i][0][0] + 1);
		}
		if (A[1][i + 1] == 0) {
			dp[i + 1][A[0][i + 1]][1] = max(dp[i + 1][A[0][i + 1]][1], dp[i][0][0] + 1);
		}
		if (A[0][i + 1] == 0 && A[1][i + 1] == 0) {
			dp[i + 1][1][1] = max(dp[i + 1][1][1], dp[i][0][1] + 1);
			dp[i + 1][1][1] = max(dp[i + 1][1][1], dp[i][1][0] + 1);
			dp[i + 1][1][1] = max(dp[i + 1][1][1], dp[i][0][0] + 1);
		}
		dp[i + 1][A[0][i + 1]][A[1][i + 1]] = max(dp[i + 1][A[0][i + 1]][A[1][i + 1]], dp[i][0][0]);
		dp[i + 1][A[0][i + 1]][A[1][i + 1]] = max(dp[i + 1][A[0][i + 1]][A[1][i + 1]], dp[i][0][1]);
		dp[i + 1][A[0][i + 1]][A[1][i + 1]] = max(dp[i + 1][A[0][i + 1]][A[1][i + 1]], dp[i][1][0]);
		dp[i + 1][A[0][i + 1]][A[1][i + 1]] = max(dp[i + 1][A[0][i + 1]][A[1][i + 1]], dp[i][1][1]);
	}
	//for (int i = 0; i <= N; i++) {
	//	cerr << dp[i][0][0] <<" " <<  dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << endl;
	//}
	int res = max(max(dp[N][0][0], dp[N][0][1]), max(dp[N][1][0], dp[N][1][1]));
	cout << res << endl;
}