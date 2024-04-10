#include <bits/stdc++.h>

using namespace std;

int n;
int pref[4001];
unordered_map<int,int> dp;

int solve(int l, int r, int k, bool igor) {
	int me = l*13651919 + r*57121 + k*239 + igor;
	if(dp.count(me))
		return dp[me];
	if(r - l + 1 < k)
		return dp[me] = 0;
	if(igor) {
		if(k < r - l + 1)
			return dp[me] = max(solve(l + k + 1, r, k + 1, !igor) + pref[l + k], solve(l + k, r, k, !igor) + pref[l + k - 1]) - pref[l - 1];
		else
			return dp[me] = solve(l + k, r, k, !igor) + pref[l + k - 1] - pref[l - 1];
	} else {
		if(k < r - l + 1)
			return dp[me] = min(solve(l, r - k - 1, k + 1, !igor) + pref[r - k - 1], solve(l, r - k, k, !igor) + pref[r - k]) - pref[r];
		else
			return dp[me] = solve(l, r - k, k, !igor) - pref[r] + pref[r - k];
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> pref[i];
		pref[i] += pref[i - 1];
	}
	dp.rehash(20000000);
	cout << solve(1, n, 1, 1);
}