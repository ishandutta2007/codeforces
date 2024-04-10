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
vector<vector<int> > dp;
vector<int> A;
int N;

int rec(int l, int r) {
	if (l >= r)return 1;
	if (dp[l][r] == -1) {
		dp[l][r] = N + 10;

		for (int i = l; i < r; i++) {
			dp[l][r] = min(dp[l][r], rec(l, i) + rec(i + 1, r));
		}
		if (A[l] == A[r]) {
			dp[l][r] = min(dp[l][r], rec(l + 1, r - 1));
		}
	}
	return dp[l][r];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	A.resize(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	dp.resize(N, vector<int>(N, -1));

	res = rec(0, N - 1);

	cout << res << endl;
}