#include <iostream>
using namespace std;

const int N = 505;

bool dp[N][N];
int a[N];
int main() {
	int n, m;
	cin >> n >> m;
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int k = m; k >= a[i]; k--) {
			for (int j = k; j >= 0; j--) {
				dp[j][k] |= dp[j][k - a[i]];
				if (j >= a[i]) {
					dp[j][k] |= dp[j - a[i]][k - a[i]];
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= m; j++) {
		if (dp[j][m])
			ans++;
	}
	cout << ans << endl;
	for (int j = 0; j <= m; j++) {
		if (dp[j][m])
			cout << j << " ";
	}
	return 0;
}