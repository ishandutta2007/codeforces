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
	
	vector<int> A(N);
	vector<int> B(N);
	{
		vector<pair<int, int> > T(N);
		for (int i = 0; i < N; i++) {
			cin >> T[i].first >> T[i].second;
		}
		sort(T.begin(), T.end());
		for (int i = 0; i < N; i++) {
			A[i] = T[i].first;
			B[i] = T[i].second;
		}
	}
	int res = N + 100;
	vector<int> dp(N, 0);
	for (int i = 0; i < N; i++) {
		int p = (int)(lower_bound(A.begin(), A.end(), A[i] - B[i]) - A.begin()) - 1;
		
		dp[i] = (p >= 0 ? dp[p] : 0) + i - p - 1;
		//cerr << i << " " << dp[i] + N - i - 1 << endl;
		res = min(res, dp[i] + N - i - 1);
	}


	cout << res << endl;
}