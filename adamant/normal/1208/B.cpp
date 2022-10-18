#include <bits/stdc++.h>
//#pragma GCC optimize ("unroll-loops")

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<int> x;
	int ans = n;
	for(int i = 0; i <= n; i++) {
		auto y = x;
		for(int j = 0; (int)y.size() == i + j && i + j <= n; j++) {
			ans = min(ans, n - (i + j));
			y.insert(a[n - j - 1]);
			
		}
		if(i < n) {
			x.insert(a[i]);
		}
	}
	cout << ans << endl;
}