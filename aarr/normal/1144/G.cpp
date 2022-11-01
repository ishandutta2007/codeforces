#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];

int dp[N][2];
int par[N][2];
int ans[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1][0] = N, dp[1][1] = -1;
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1]) {
			dp[i][0] = dp[i - 1][0];
			par[i][0] = 0;
			if (dp[i - 1][1] < a[i] && a[i - 1] > dp[i][0]) {
			//	cout << 73 << endl;
				dp[i][0] = a[i - 1];
				par[i][0] = 1;
			}
		}
		if (a[i] >= a[i - 1]) {
			par[i][1] = 0;
			if (dp[i - 1][0] > a[i]) {
				dp[i][1] = a[i - 1];
			}
			else {
				dp[i][1] = N;
			}
		}
		if (a[i] < a[i - 1]) {
			dp[i][1] = dp[i - 1][1];
			par[i][1] = 1;
			if (dp[i - 1][0] > a[i] && a[i - 1] < dp[i][1]) {
			//	cout << 74 << endl;
				dp[i][1] = a[i - 1];
				par[i][1] = 0;
			}
		}
		if (a[i] <= a[i - 1]) {
			par[i][0] = 1;
			if (dp[i - 1][1] < a[i]) {
				dp[i][0] = a[i - 1];
			}
			else {
				dp[i][0] = -1;
			}
		}
	//	cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
	}
//	cout << dp[n][0] << " " << dp[n][1] << endl;
	if (dp[n][0] == -1 && dp[n][1] == N) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		int x;
		if (dp[n][0] != -1) {
			x = 0;
		}
		else {
			x = 1;
		}
		for (int i = n; i; i--) {
			ans[i] = x;
			x = par[i][x];
		}
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
	}
	return 0;
}