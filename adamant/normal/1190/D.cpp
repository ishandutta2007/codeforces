#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, vector<int>, greater<int>> xx;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		xx[y].push_back(x);
	}
	ordered_set xs;
	int ans = 0;
	for(auto it: xx) {
		sort(all(it.second));
		for(auto jt: it.second) {
			xs.insert(jt);
		}
		int sz = xs.size();
		ans += sz * (sz + 1) / 2;
		for(size_t i = 1; i < it.second.size(); i++) {
			if(it.second[i - 1] < it.second[i]) {
				int t = xs.order_of_key(it.second[i]) - xs.order_of_key(it.second[i - 1] + 1);
				ans -= t * (t + 1) / 2;
			}
		}
		int t = xs.order_of_key(it.second[0]);
		ans -= t * (t + 1) / 2;
		t = xs.size() - xs.order_of_key(it.second.back() + 1);
		ans -= t * (t + 1) / 2;
	}
	cout << ans << endl;
	return 0;
}