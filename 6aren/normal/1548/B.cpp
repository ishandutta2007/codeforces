#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &e : a) cin >> e;
	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	vector<int> b(n);
	for (int i = 1; i < n; i++) b[i] = abs(a[i] - a[i - 1]);
	vector<pair<int,int>> foo;
	foo.push_back({1, 0});
	int res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < foo.size(); j++) {
			foo[j].first = __gcd(foo[j].first, b[i]);
		}
		foo.push_back({b[i], i});
		vector<pair<int, int>> new_foo;
		for (int j = (int) foo.size() - 1; j >= 0; j--) {
			if (new_foo.empty() || foo[j].first != new_foo.back().first) {
				new_foo.push_back(foo[j]);
			}
		}
		reverse(new_foo.begin(), new_foo.end());
		// cout << i << endl;
		// for (auto e : new_foo) cout << e.first << ' ' << e.second << endl;
		res = max(res, i - new_foo[0].second + 1);
		// cout << i << ' ' << new_foo[0].second << endl;
		foo = new_foo;
	}
 
	cout << res << '\n';
}
 
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) solve();
}