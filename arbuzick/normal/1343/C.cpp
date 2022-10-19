#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n, k;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		int x = a[0], ans = 0;
		for (int i = 1; i < n; ++i) {
			if ((a[i] > 0 && a[i - 1] > 0) || (a[i] < 0 && a[i - 1] < 0)) 
				x = max(x, a[i]);
			else {
				ans += x;
				x = a[i];
			}
		}
		ans += x;
		cout << ans << endl;
	}
	return 0;
}