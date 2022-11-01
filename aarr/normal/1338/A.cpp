#include <bits/stdc++.h>
using namespace std;

const int inf = 1000 * 1000 * 1000 + 7;


int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0 ; ii < t; ii++) {
		int n, ans = 0;
		cin >> n;
		int maxi = -inf;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			ans = max(ans, maxi - x);
			maxi = max(maxi, x);
		}
		if (ans == 0) {
			cout << 0 << endl;
		}
		else
			cout << 32 - __builtin_clz(ans) << '\n';
	}
	
	return 0;
}