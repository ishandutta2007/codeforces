#include <bits/stdc++.h>
using namespace std;


const int N = 505;

int cnt[N];
long long dp[N][N];


int main() {
	int n, m, mod;
	cin >> n >> m >> mod;
	for (int i = 1; i <= m; i++) {
		int s = 0;
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '1') {
				cnt[j]++;
				s++;
			}
		}
		if (s != 2) {
			cout << 0;
			return 0;
		}
	}
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > 2) {
			cout << 0;
			return 0;
		}
		if (cnt[i] == 1) {
			y++;
		}
		if (cnt[i] == 0) {
			x++;
		}
	}
//	cout << "75 " << x << " " << y << endl;
	dp[0][0] = 1;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= x + y; j++) {
			if (i >= 2) {
				dp[i][j] += i * (i - 1) / 2 * dp[i - 2][j + 2];
			}
			if (i && j) {
				dp[i][j] += i * j * dp[i - 1][j];
			} 
			if (j >= 2) {
				dp[i][j] += j * (j - 1) / 2 * dp[i][j - 2];
			}
			dp[i][j] %= mod;
		//	cout << "73 " << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	cout << dp[x][y];
	return 0;
}