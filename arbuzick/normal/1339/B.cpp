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
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		sort(a.begin(), a.end());
		vector<int> ans(n);
		for (int j = 0; j < n; ++j) {
			if (j % 2 == 0)
				ans[j] = a[j / 2];
			else
				ans[j] = a[n - (j+1)/2];
		}
		reverse(ans.begin(), ans.end());
		for (int j = 0; j < n; ++j)
			cout << ans[j] << ' ';
		cout << endl;
	}
	return 0;
}