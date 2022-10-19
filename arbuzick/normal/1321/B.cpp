#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int>b(n);
	vector<vector<int>> c(600000);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		c[i - b[i] + 400000].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < 600000; ++i) {
		int ans1;
		ans1 = 0;
		for (int j = 0; j < c[i].size(); ++j)
			ans1 += b[c[i][j]];
		ans = max(ans, ans1);
	}
	cout << ans;
	return 0;
}