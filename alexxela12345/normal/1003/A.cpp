#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	map<int, int> m;
	for (int el : arr) {
		m[el] += 1;
	}
	int ans = 0;
	for (auto el : m) {
		ans = max(ans, el.second);
	}
	cout << ans << endl;
	return 0;
}