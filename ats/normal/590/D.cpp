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
	int N, K, S;
	cin >> N >> K >> S;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	S = min(S, (N - K) * K);
	int INF = (int)1 << 60;
	vector<vector<int> > dp(K + 1, vector<int>(S + 1, INF));
	vector<vector<int> > ndp(K + 1, vector<int>(S + 1, INF));
	dp[0][0] = 0;
	ndp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < K&& i - k>=0; k++) {
			for (int s = 0; s + i - k <= S; s++) {
				if (dp[k][s] < INF) {
					ndp[k + 1][s + i - k] = min(dp[k + 1][s + i - k], dp[k][s] + A[i]);
				}
			}
		}
		dp = ndp;
	}
	int res = INF;
	for (int s = 0; s <= S; s++) {
		res = min(res, dp[K][s]);
	}
	cout << res << endl;
}