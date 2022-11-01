#include <iostream>
using namespace std;

const int N = 1000 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;

int h[N];

long long dp[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = min(h[i - 1], h[i]);
		x = min(x, h[i + 1]);
		dp[i] = 1ll * dp[i - 1] * (x - 1);
		dp[i] += min(h[i], h[i + 1]) - 1;
		ans += 1ll * dp[i - 1] * (min(h[i], h[i - 1]) - 1);
		ans += h[i] - 1;
	//	cout << i << " " << (1ll * dp[i - 1]) * (min(h[i], h[i - 1]) - 1) << " " << dp[i] << endl;
		dp[i] %= mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}