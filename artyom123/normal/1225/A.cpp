#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define int long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int a1, b1;
	cin >> a1 >> b1;
	if (a1 == b1) {
		cout << a1 << 0 << " " << b1 << 1;
		return 0;
	}
	if (a1 == b1 - 1) {
		cout << a1 << 9 << " " << b1 << 0;
		return 0;
	}
	if (a1 == 9 && b1 == 1) {
		cout << 9 << " " << 10;
		return 0;
	}
	cout << -1;
	return 0;
}