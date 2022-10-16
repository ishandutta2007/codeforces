#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> v = a;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int& x : a) {
		x = lower_bound(v.begin(), v.end(), x) - v.begin();
	}
	vector<vector<int>> locs(n);
	for (int i = 0; i < n; ++i) {
		locs[a[i]].push_back(i);
	}
	int ans = -1;
	for (auto& v : locs) {
		int sz = (int)v.size();
		for (int i = 0; i < sz - 1; ++i) {
			int x = v[i];
			int y = v[i + 1];
			ans = max(ans, n - 1 - (y - x) + 1);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}