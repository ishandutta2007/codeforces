#include <iostream>
#include <algorithm>
using namespace std;


const int N = 105, S = N * N, mod = 1000 * 1000 * 1000 + 7;


int a[N];
int cnt[N];
int dp[N][S];
int f[N][N];
int main() {
	bool b = false;
	int n, s = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (cnt[a[i]] == 0) {
			s++;	
		}
		cnt[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	dp[0][0] = 1;
	int t = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			t = 0;
		}
		t++;
		for (int j = n; j > 0; j--) {
			for (int k = a[i]; k < n * N; k++) {
				dp[j][k] += dp[j - 1][k - a[i]];
				dp[j][k] %= mod;
			}
		}
	//	f[i] = dp[t][a[i] * t];
		for (int j = 1; j <= t; j++) {
			f[a[i]][j] = dp[j][a[i] * j];
		//	cout << a[i] << " " << j << endl;
		}
	//	cout << i << " " << a[i] << " " << t << " " << f[i] << endl;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			t = 0;
		}
		t++;
		if (f[a[i]][t] == dp[t][a[i] * t]) {
			ans = max(ans, t);
			if (t == cnt[a[i]]) {
				b = true;
			}
		}
	}
	if (b && s == 2) {
		cout << n;
	}
	else
		cout << ans;
	return 0;
}