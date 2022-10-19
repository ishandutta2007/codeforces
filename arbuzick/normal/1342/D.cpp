#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> m(n);
	for (int i = 0; i < n; ++i)
		cin >> m[i];
	vector<int> c(k);
	for (int i = 0; i < k; ++i)
		cin >> c[i];
	sort(m.begin(), m.end());
	int ans = 0;
	int ind = -1;
	for (int i = 0; i < k; ++i) {
		while (ind + 1 < n && m[ind + 1] < i+1)
			ind += 1;
		int a = n - (ind + 1);
		ans = max(ans, (a - 1) / c[i] + 1);
	}
	cout << ans << "\n";
	vector<vector<int>> ans1(ans);
	ind = 0;
	for (int i = 0; i < n; ++i) {
		ans1[ind].push_back(m[i]);
		ind += 1;
		ind %= ans;
	}
	for (int i = 0; i < ans; ++i) {
		cout << ans1[i].size() << ' ';
		for (int j = 0; j < ans1[i].size(); ++j)
			cout << ans1[i][j] << ' ';
		cout << "\n";
	}
	return 0;
}