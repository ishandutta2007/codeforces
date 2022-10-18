#include <bits/stdc++.h>
//#pragma GCC optimize ("unroll-loops")

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)


void solve() {
	int a, b, n;
	cin >> a >> b >> n;
	// a, b, a+b, a, b, a+b
	if(n % 3 == 0) {
		cout << a << "\n";
	} else if(n % 3 == 1) {
		cout << b << "\n";
	} else {
		cout << (a ^ b) << "\n";
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
}