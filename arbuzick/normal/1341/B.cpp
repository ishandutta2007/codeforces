#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		vector<int> pr(n + 1);
		pr[0] = 0;
		for (int j = 1; j < n-1; ++j) {
			if (a[j] > a[j - 1] && a[j] > a[j + 1])
				pr[j] = pr[j-1] + 1;
			else
				pr[j] = pr[j-1];
		}
		pr[n - 1] = pr[n - 2];
		int l = 1, ans = 1;
		for (int j = 0; j < n-k+1; ++j) {
			int ans1 = pr[j + k - 2] - pr[j]+1;
			if (ans1 > ans) {
				ans = ans1;
				l = j + 1;
			}
		}
		cout << ans << ' ' << l << endl;
	}
	return 0;
}