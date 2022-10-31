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
	int res = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int mx = A[0];
	int mn = A[0];
	for (int i = 0; i < N; i++) {
		A.push_back(A[i]);
		mx = max(A[i], mx);
		mn = min(A[i], mn);
	}
	if (mn * 2 >= mx) {
		for (int i = 0; i < N; i++) {
			if (i > 0)cout << " ";
			cout << -1;
		}
		cout << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		A.push_back(A[i]);
	}
	map<int, int> mp;
	mp[0] = 3 * N;
	mp[2 * A.back()] = 3 * N - 1;
	vector<int> dp(3 * N);
	dp[3 * N - 1] = 3 * N;
	for (int i = 3 * N - 2; i >= 0; i--) {
		auto m = mp.lower_bound(A[i]);
		--m;
		dp[i] = min(dp[i + 1], (*m).second);

		m = mp.upper_bound(2 * A[i]);
		while (m != mp.end()) {
			m = mp.erase(m);
		}
		mp[2 * A[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << dp[i] - i;
	}
	cout << endl;
}