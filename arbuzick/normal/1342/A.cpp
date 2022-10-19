#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x, y;
		cin >> x >> y;
		int a, b;
		cin >> a >> b;
		if (a * 2 <= b)
			cout << (x + y) * a << "\n";
		else
			cout << min(x, y) * b + abs(x - y) * a << "\n";
	}
	return 0;
}