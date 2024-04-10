#include <iostream>
using namespace std;

const int N = 15, M = 1000 * 1000 * 1000 + 7;


int dp[(1 << N) + 5][N + 5];
pair <int, int> a[N + 5];
int get(int n, int m) {
	return (n >> m) % 2;
}
int main() {
	int n, t;
	cin >> n;
	cin >> t;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		cin >> a[i].second;
	}
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (get(i, j) == 0)
				continue;
			if (i == 1 << j) {
				dp[i][j] = 1;
				//cout << i << " " << j << " " << dp[i][j] << endl;
				continue;
			}
			for (int k = 0; k < n; k++) {
				if (get(i, k) == 1 && a[j].second != a[k].second) {
					dp[i][j] += dp[i - (1 << j)][k];
					dp[i][j] %= M;
				}
			}
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
		
	}
	long long ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		int x = 0;
		for (int k = 0; k < n; k++) {
			if (get(i, k) == 1) {
				x += a[k].first;
			}
		}
		if (x == t) {
			for (int j = 0; j < n; j++) {
				ans += dp[i][j];
				ans %= M;
			}
		}
	}
	cout << ans;
	return 0;
}