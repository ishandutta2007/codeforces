#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, S;
	cin >> n >> S;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r = n + 1;
	while(r - l > 1) {
		int m = (l + r) / 2;
		int b[n];
		for(int i = 0; i < n; i++) {
			b[i] = a[i] + m * (i + 1);
		}
		sort(b, b + n);
		int t = accumulate(b, b + m, 0LL);
		if(t <= S) {
			l = m;
		} else {
			r = m;
		}
	}
	int b[n];
	for(int i = 0; i < n; i++) {
		b[i] = a[i] + l * (i + 1);
	}
	sort(b, b + n);
	int t = accumulate(b, b + l, 0LL);
	cout << l << ' ' << t << endl;
	return 0;
}