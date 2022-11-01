#include <iostream>
#include <cmath>
using namespace std;

const int N = 2005, inf = 2000 * 1000 * 1000 + 7;
int n, k; 

int a[N];
int dp[N];
bool isval(int x) {
	dp[1] = 0;
	int ans = n - 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = i - 1;
		for (int j = 1; j < i; j++) {
			int y = (int) ceil((double) abs(a[i] - a[j]) / (i - j));
			if (y <= x) {
				dp[i] = min(dp[i], dp[j] + i - j - 1);
			}
		}
	//	cout << x << " " << i << " " << dp[i] << endl;
		ans = min(ans, dp[i] + n - i);
	}
//	cout << "73 " << ans << endl;
	if (ans <= k) {
		return true;
	}
	return false;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long dw = -1, up = inf;
	while (up - dw > 1) {
		long long md = dw + up - (dw + up) / 2;
		if (isval(md)) {
			up = md;
		}
		else {
			dw = md;
		}
	}
	cout << up << endl;
	return 0;
}