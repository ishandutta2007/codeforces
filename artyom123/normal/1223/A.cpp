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
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		if (n < 4) {
			cout << 4 - n << "\n";
			continue;
		}
		cout << n % 2 << "\n";
	}
	return 0;
}