#include<bits/stdc++.h>

using namespace std;

int n, a[100005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	int mx = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		if (mx == i) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}