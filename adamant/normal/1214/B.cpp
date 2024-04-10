#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

signed main() {
	int b, g, n;
	cin >> b >> g >> n;
	/* x + y = n
	 * x <= b
	 * n - x <= g
	 */
	
	cout << min(b, n) - max(0, n - g) + 1 << endl;
    return 0;
}