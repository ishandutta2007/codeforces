#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

const int maxn = 2e5 + 42;
int cnt[maxn];

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if(k == n) {
		cout << a[n - 1] << endl;
	} else if(k == 0) {
		if(a[0] == 1) {
			cout << -1 << endl;
		} else {
			cout << 1 << endl;
		}
	} else {
		if(a[k - 1] == a[k]) {
			cout << -1 << endl;
		} else {
			cout << a[k - 1] << endl;
		}
	}
	return 0;
}