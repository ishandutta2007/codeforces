#include <iostream>
#include <deque>
using namespace std;

const int N = 150 * 1000 + 5, M = 305;
const long long inf = 1ll * 1000 * 1000 * 1000 * 1000 + 1000 * 1000 + 7;

long long dp[3][2 * N];
int a[M];
int b[M];
int t[M];
deque<int> q;

int32_t main() {
	int n, m, d;
	cin >> n;
	cin >> m;
	cin >> d;
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		cin >> b[i];
		cin >> t[i];
		ans += b[i];
	}
	for (int j = 0; j <= 2 * n; j++) {
		dp[0][j] = -inf;
		dp[1][j] = -inf;
	}
	for (int j = 1; j <= n; j++) {
		dp[1][j] = -abs(j - a[1]);
	//	cout << 1 << " " << j << " " << dp[1][j] << endl;
	}
	for (int i = 2; i <= m; i++) {
		long long x = min(1ll * d * (t[i] - t[i - 1]), 1ll * n);
		q.clear();
		for (int j = 1; j <= n + x; j++) {
			while (q.size() && dp[1 - i % 2][q.back()] < dp[1 - i % 2][j])
				q.pop_back();
			q.push_back(j);
			if (q.size() && q.front() < j - 2 * x)
				q.pop_front();
			if (j > x) {
				long long y = dp[1 - i % 2][q.front()];
				dp[i % 2][j - x] = y - abs(a[i] - j + x);
	//			cout << i << " " << j - x << " " << q.front() << " " << x << " " << dp[i][j - x] << endl;
			}
		}
	}
	long long maxi = -inf;
	for (int j = 1; j <= n; j++) {
		maxi = max(maxi, dp[m % 2][j]);
	}
	ans += maxi;
	cout << ans << endl;
	return 0;
}