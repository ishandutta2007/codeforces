#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
int dp[N];

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, p, k;
		cin >> n >> p >> k;
		int p2 = p;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		if (a[1] > p) {
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		dp[0] = p;
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1] - a[i];
			if (i >= k) {
				dp[i] = dp[i - k] - a[i];
			}
			if (dp[i] >= 0) {
				ans = i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}