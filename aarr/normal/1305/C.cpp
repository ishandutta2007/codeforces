#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200 * 1000 + 5;
int n, m;
int a[N];
int c[N];

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	int ans = po(x, y / 2);
	ans *= ans;
	ans %= m;
	if (y % 2) {
		ans *= x;
		ans %= m;
	}
	return ans;
}
int32_t main() {
	ios :: sync_with_stdio(false);
	long long ans = 1,s = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n > m) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			ans *= abs(a[i] - a[j]);
			ans %= m;
		}
	}
	cout << ans;
	return 0;
}