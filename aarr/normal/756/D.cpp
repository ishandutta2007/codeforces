#include <iostream>
using namespace std;

const int N = 5005, A = 30;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[N][A];
int chs[N][N];
int sum[N];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int j = 0; j < n; j++) {
		if (dp[1][s[j] - 'a'] == 0) {
			dp[1][s[j] - 'a'] = 1;
			sum[1]++;
		}
	//	sum[1]++;
	//	dp[1][s[j] - 'a']++;
		for (int i = 2; i <= n; i++) {
			sum[i] -= dp[i][s[j] - 'a'];
			dp[i][s[j] - 'a'] = sum[i - 1] - dp[i - 1][s[j] - 'a'] + mod;
			dp[i][s[j] - 'a'] %= mod;
			sum[i] += dp[i][s[j] - 'a'];
			if (sum[i] < 0)
				sum[i] += mod;
			sum[i] %= mod;
		//	cout << j << " " << i << " " << dp[i][s[j] - 'a'] << endl;
		}
	}
	chs[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			chs[i][j] = chs[i - 1][j];
			if (j > 0) {
				chs[i][j] += chs[i - 1][j - 1];
				chs[i][j] %= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
	//	cout << i << " " << sum[i] << endl;
		ans += 1ll * sum[i] * chs[n - 1][i - 1];
		ans %= mod;
	}
	cout << ans;
}