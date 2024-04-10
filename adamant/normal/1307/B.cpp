#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9;

void solve() {
	int n, x;
	cin >> n >> x;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int d = *max_element(a, a + n);
	if(d > x) {
		for(int i = 0; i < n; i++) {
			if(a[i] == x) {
				cout << 1 << "\n";
				return;
			}
		}
		cout << 2 << endl;
	} else {
		cout << (x + d - 1) / d << "\n";
	}
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