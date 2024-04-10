#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;

int a[N];
int mark[N];
int mark2[N];
int dp[N];
int l[N];
int r[N];
int cnt[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i > 0; i--) {
		int x = lower_bound(dp + 1, dp + n + 1, -a[i]) - dp;
	//	if (dp[x] != 0) {
	//		mark[i] = true;
	//	}
		r[i] = x;
		dp[x] = -a[i];
		
	}
	for (int i = 0; i <= n; i++) {
		dp[i] = inf;
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		int x = lower_bound(dp + 1, dp + n + 1, a[i]) - dp;
	//	if (dp[x] != inf) {
	//		mark[i] = true;
	//	}
		l[i] = x;
		dp[x] = a[i];
		maxi = max(maxi, x);
	}
	for (int i = 1; i <= n; i++) {
		if (l[i] + r[i] == maxi + 1) {
			cnt[l[i]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		int ans = 1;
		if (l[i] + r[i] == maxi + 1) {
			if (cnt[l[i]] == 1) {
				ans = 3;
			}
			else {
				ans = 2;
			}
		}
		cout << ans;
	}
	return 0;
}