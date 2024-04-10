#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	vector<int> ans = {0};
	cin >> a[0];
	int sum = a[0], total = a[0];
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		if(a[0] >= 2 * a[i]) {
			sum += a[i];
			ans.push_back(i);
		}
		total += a[i];
	}
	if(2 * sum > total) {
		cout << ans.size() << endl;
		for(auto it: ans) {
			cout << it + 1 << ' ';
		}
	} else {
		cout << 0 << endl;
	}
	return 0;
}