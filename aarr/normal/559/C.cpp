#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2005, H = 200 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;

pair <int, int> a[N];
long long fac[H];
long long facp[H];
int dp[N];
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

int chs(int x, int y) {
	if (y > x || y < 0) 
		return 0;
	long long ans = fac[x];
	ans *= facp[y];
	ans %= mod;
	ans *= facp[x - y];
	ans %= mod;
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	int h, w, n;
	cin >> h >> w >> n;
	fac[0] = 1;
	facp[0] = 1;
	for (int i = 1; i <= h + w; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
		facp[i] = po(fac[i], mod - 2);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	a[n] = {1, 1};
	sort(a, a + n + 1);
	for (int i = n; i >= 0; i--) {
		dp[i] = chs(h - a[i].first + w - a[i].second, h  - a[i].first);
		for (int j = i + 1; j <= n; j++) {
			long long x = 1ll * chs(a[j].first - a[i].first + a[j].second - a[i].second, a[j].first - a[i].first) * dp[j];
			x %= mod;
			dp[i] += mod - x;
			dp[i] %= mod;
		}
	}
	cout << dp[0] << endl;
	return 0;
}