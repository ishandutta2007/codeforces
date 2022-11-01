#include <iostream>
using namespace std;

const int N = 505;
const int inf = 1000 * 1000 * 1000 + 7;

int dp[N][N];
int a[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int l = 0; l + i < n; l++) {
			int r = l + i;
			dp[l][r] = inf;
			for (int k = l; k < r; k++) {
				if (a[k] == a[l]) {
					dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
				}
			}
			if (a[l] == a[r]) {
				if (r - l == 1) {
					dp[l][r] = 1;
				}
				else {
					dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
				}
			}
		//	cout << l << " " << r << " " << dp[l][r] << endl;
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}