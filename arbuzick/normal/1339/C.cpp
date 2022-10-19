#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n; 
		cin >> n;
		vector<int> a(n);
		int m = -1e9-1, ans1 = 0;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			m = max(m, a[j]);
			ans1 = max(ans1, m - a[j]);
		}
		if (ans1 == 0)
			cout << 0 << endl;
		else {
			int st = 0;
			for (int s = 1; s < 60; ++s) {
				st = st + (1 << (s - 1));
				if (st >= ans1){
					cout << s << endl;
					break;
				}
			}
		}
	}
	return 0;
}