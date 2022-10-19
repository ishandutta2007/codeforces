#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long long ll;
typedef long double ldb;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	int n;
	cin >> n;
	vector<int> arr(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i] - i - 1] += arr[i];
	}
	int mx = INT_MIN;
	for (auto &el : m) {
		mx = max(mx, el.second);
	}
	cout << mx;
	cout << endl;
	return 0;
}