#include<bits/stdc++.h>

using namespace std;

int n, a[2345];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	int cntodd = 0, cnteven = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] % 2) cntodd++;
		else cnteven++;
	}
	sort(a + 1, a + 1 + n);
	if (abs(cntodd - cnteven) <= 1) cout << 0;
	else if (cntodd < cnteven) {
		long long ans = 0;
		int u = cnteven - cntodd - 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2) continue;
			ans += a[i];
			u--;
			if (u == 0) break;
		}
		cout << ans;
	} else {
		long long ans = 0;
		int u = cntodd - cnteven - 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2 == 0) continue;
			ans += a[i];
			u--;
			if (u == 0) break;
		}
		cout << ans;
	}
	return 0;
}