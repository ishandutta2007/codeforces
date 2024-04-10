#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9;

void solve() {
	int n, d;
	cin >> n >> d;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i > 0) {
			int t = min(d / i, a[i]);
			a[0] += t;
			d -= t * i;
		}
	}
	cout << a[0] << "\n";
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
	return 0;
}