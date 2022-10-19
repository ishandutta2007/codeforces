//
#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, k, l;
int a[N], dp[N], op[N];
int pref[N], pref_op[N];

int calc(int cost) {
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + a[i];
		op[i] = op[i - 1];
		if (i < l && dp[i] < i - cost) {
			dp[i] = i - cost;
			op[i] = 1;
		}
		if (i >= l && dp[i] < dp[i - l] + l - cost) {
			dp[i] = dp[i - l] + l - cost;
			op[i] = op[i - l] + 1;
		}
	}
	return op[n];
}

int solve() {
	int le = 0, ri = l;

	int res = 0;
	while (ri >= le) {
		int mid = (le + ri) / 2;
		if (calc(mid) <= k) {
			res = mid;
			ri = mid - 1;
		} else le = mid + 1;
	}

	int foo = calc(res);


	return dp[n] + k * res;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k >> l;
	string s;
	cin >> s;

	for (int i = 1; i <= n; i++) {
		a[i] = (islower(s[i - 1]) > 0);
	}

	int ans = solve();

	for (int i = 1; i <= n; i++) 
		a[i] = 1 - a[i];

	ans = max(ans, solve());

	cout << n - ans << endl;

	return 0;
}