#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int pa[n], pb[n];
	iota(pa, pa + n, 0);
	iota(pb, pb + n, 0);
	sort(pa, pa + n, [&](int x, int y){return a[x] < a[y];});
	sort(pb, pb + n, [&](int x, int y){return b[x] < b[y];});
	for(int i = 0; i < n; i++) {
		cout << a[pa[i]] << " \n"[i + 1 == n];
	}
	for(int i = 0; i < n; i++) {
		cout << b[pb[i]] << " \n"[i + 1 == n];
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