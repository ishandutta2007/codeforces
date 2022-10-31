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
	int N, T;
	cin >> N >> T; T--;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<vector<int> > dp(150, vector<int>(N, 1));
	
	for (int i = 0; i < 150; i++) {
		for (int j = 0; j < N; j++) {

			for (int k = 0; k < j; k++) {
				if (A[k] <= A[j]) {
					dp[i][j] = max(dp[i][j], dp[i][k] + 1);
				}
			}
			if (i > 0) {
				for (int k = j; k < N; k++) {
					if (A[k] <= A[j]) {
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
					}
				}
			}
		}
	}
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			cerr << dp[i][j] << " ";
		}
		cerr << endl;
	}*/


	int res = 0;
	if (T < 150) {
		for (int i = 0; i < N; i++) {
			res = max(res, dp[T][i]);
		}
	}
	else {

		int a120 = 0;
		for (int i = 0; i < N; i++) {
			a120 = max(a120, dp[120][i]);
		}

		int a121 = 0;
		for (int i = 0; i < N; i++) {
			a121 = max(a121, dp[121][i]);
		}
		int diff = a121 - a120;
		res = (T - 120) * diff + a120;

	}
	cout << res << endl;
}