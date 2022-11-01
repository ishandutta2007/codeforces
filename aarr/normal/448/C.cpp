#include <iostream>
using namespace std;


const int N = 5005, inf = 1000 * 1000 * 1000 + 7;

int dp[N][N];
int mn[N];
int a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 1; j <= n; j++) {
		dp[0][j] = inf;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][0] = mn[i - 1] + 1;
		mn[i] = dp[i][0];
		int x = dp[i - 1][0];
		for (int j = 1; j <= n; j++) {
			x = min(x + 1, dp[i - 1][j]);
			if (j > a[i]) {
				dp[i][j] = inf;
			}
			else {
				dp[i][j] = x;
				if (a[i] > j) {
					dp[i][j]++;
				}
				mn[i] = min(mn[i], dp[i][j]);
			}
		//	cout << i << " " << j << " " << dp[i][j] << endl;
		}
		for (int j = n; j; j--) {
			dp[i][j - 1] = min(dp[i][j - 1], dp[i][j]);
		}
	}
	cout << mn[n];
	return 0;
}