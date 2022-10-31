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
vector<int> dp;
vector<int> A;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	A.resize(1000002, 0);
	dp.resize(1000002, 0);
	int res = 0;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		A[a]++;
	}


	for (int i = 1; i <= 1000000; i++) {
		if (A[i] > 0) {
			dp[i] = max(A[i], dp[i]);
			for (int j = 2*i; j <= 1000000; j += i) {
				if (A[j] > 0) {
					dp[j] = max(dp[j], dp[i] + A[j]);
					//cerr << i << " " << j << " " << dp[j] << endl;
				}
			}
		}
	}
	res = *max_element(dp.begin(), dp.end());

	cout << res << endl;
}