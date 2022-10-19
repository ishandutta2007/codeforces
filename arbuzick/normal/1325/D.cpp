#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	cin >> u >> v;
	if (u > v || u % 2 != v % 2)
		cout << -1;
	else {
		if (u == 0 && v == 0)
			cout << 0;
		else if (u == v) {
			cout << 1 << endl;
			cout << u;
		}
		else {
			int x;
			x = (v - u) / 2;
			if ((x & u) == 0) {
				cout << 2 << endl;
				cout << u + x << " " << x;
			}
			else {
				cout << 3 << endl;
				cout << u << " " << x << " " << x;
			}
		}
	}
	return 0;
}