#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % mod;
}
int sub(int a, int b) {
	return (a + mod - b) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	vector<int> spl[2];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		spl[i % 2].push_back(a[i]);
	}
	sort(all(spl[0]), greater<int>());
	sort(all(spl[1]), greater<int>());
	for(int i = 0; i < n; i++) {
		a[i] = spl[i % 2].back();
		spl[i % 2].pop_back();
	}
	cout << (is_sorted(a, a + n) ? "YES" : "NO") << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}