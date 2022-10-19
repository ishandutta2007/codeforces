#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, m;
	cin >> n >> m;
	int pos = 1;
	int ans = INT32_MAX;
	int val = -1;
	cout << "? 1 1" << endl;
	cin >> val;
	for (int i = 2; i <= m; i++) {
		cout << "? 1 " << i << endl;
		int x;
		cin >> x;
		if (x < val) {
			pos = i;
			val = x;
		}
	}
	ans = val;
	for (int i = 2; i <= n; i++) {
		cout << "? " << i << ' ' << pos << endl;
		int x;
		cin >> x;
		ans = min(ans, x);
	}
	cout << "! " << ans << endl;
    return 0;
}