#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 && (a != 0 || b != 0))
			cout << "NO" << endl;
		else if (y1 == y2 && (c != 0 || d != 0))
			cout << "NO" << endl;
		else {
			int xn, yn;
			xn = x + b - a;
			yn = y + d - c;
			if (xn < x1 || xn > x2 || yn < y1 || yn > y2)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}