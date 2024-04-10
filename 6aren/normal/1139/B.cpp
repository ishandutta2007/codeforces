#include<bits/stdc++.h>

using namespace std;

int n, a[200005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int tmp = 1e9 + 1;
	long long ans = 0;
	for (int i = n; i >= 1; i--) {
		if (tmp > a[i]) {
			tmp = a[i];
		} else {
			tmp = max(0, tmp - 1);
		}
		ans += tmp;
	}
	cout << ans;
	return 0;
}