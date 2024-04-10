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
	int N, K;
	cin >> N >> K;
	vector<int> res(N);
	vector<int> dp(N + 1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]);
	}

	for (int i = 0; i < N; i++) {
		res[i] = i + 1;
	}
	for (int i = 0; i < N - 1;) {
		int c = dp[N - i - 1];
		if (K <= c) {
			i++;
		}
		else {
			K -= c;
			swap(res[i], res[i + 1]);
			i += 2;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}