#ifndef DEBUG
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
typedef long long ll;
typedef long double ldb;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> cntin(n);
	for (int i = 0; i < n; i++) {
		cntin[((i + a[i]) % n + n) % n]++;
	}
	if ((*min_element(cntin.begin(), cntin.end()) == 0)) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
			
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(12);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/