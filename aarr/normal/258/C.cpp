#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;

int a[N];
vector <int> d[N];
long long dp[N];
int cnt[N];
int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = N - 2; i; i--) {
		cnt[i] += cnt[i + 1];
	//	cout << "48 " << i << " " << cnt[i] << endl;
	}
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			d[j].push_back(i);
		}
	}
	int ans = 0;
	for (int i = 1; i < N; i++) {
		dp[i] = po(d[i].size(), cnt[d[i].back()]);
		dp[i] -= po((int) d[i].size() - 1, cnt[d[i].back()]) - mod;
		dp[i] %= mod;
		for (int j = 0; j < (int) d[i].size() - 1; j++) {
	//		cout << "73 " << i << " " << j << " " << d[i][j] << endl;
			dp[i] *= po(j + 1, cnt[d[i][j]] - cnt[d[i][j + 1]]);
			dp[i] %= mod;
		}
	//	cout << i << " " << dp[i] << endl;
	//	for (int j = 0; j < (int) d[i].size() - 1; j++) {
	//		dp[i] += mod - dp[d[i][j]];
	//		dp[i] %= mod;
	//	}
	//	cout << i << " " << dp[i] << endl;
		ans += dp[i];
		ans %= mod;
	}
	cout << ans;
	return 0;
}