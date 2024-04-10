#include <iostream>
using namespace std;

const int N = 1000 * 1000 + 5, LG = 20;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[(1 << LG) + 5][LG + 3];
int po2[(1 << LG) + 1];

int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n;
	cin >> n;
	po2[0] = 1;
	for (int i = 1; i <= n; i++) {
		po2[i] = po2[i - 1] * 2;
		po2[i] %= mod;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		dp[x][LG]++;
	}
	long long ans = 0;
	for (int i = (1 << LG) - 1; i >= 0; i--) {
		for (int j = LG - 1; j >= 0; j--) {
			dp[i][j] = dp[i][j + 1];
			if (!get(i, j)) {
				dp[i][j] += dp[i + (1 << j)][j + 1];
			}
		}
		long long x = po2[dp[i][0]];
		if (__builtin_popcount(i) % 2) {
			ans -= x;
		}
		else {
			ans += x;
		}
		ans += mod;
		ans %= mod;
	}
	cout << ans;
	return 0;
}