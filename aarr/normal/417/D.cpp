#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 105, M = 21;
const long long inf = 2000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 7;

pair < pair <int, int>, int> a[N];
long long dp[1 << M];
int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n, m, b;
	cin >> n >> m >> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first.second;
		cin >> a[i].first.first;
		int x;
		cin >> x;
		for (int j = 0; j < x; j++) {
			int y;
			cin >> y;
			a[i].second += (1 << (y - 1));
		}
	}
	sort(a + 1, a + n + 1);
	for (int mask = 1; mask < (1 << m); mask++) {
		dp[mask] = inf;
	}
	dp[0] = 0;
	long long ans = inf;
	for (int i = 1; i <= n; i++) {
		int x = a[i].first.first, y = a[i].first.second, z = a[i].second;
		for (int mask = 0; mask < (1 << m); mask++) {
			dp[mask | z] = min(dp[mask | z], dp[mask] + y);
		}
		ans = min(ans, dp[(1 << m) - 1] + 1ll * b * x);
	}
	if (ans == inf)	{
		cout << -1 << endl;
	}
	else
		cout << ans;
	return 0;
}