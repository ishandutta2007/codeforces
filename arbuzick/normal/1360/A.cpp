#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << min(max(a * 2, b) * max(a * 2, b), max(a, b * 2) * max(a, b * 2)) << "\n";
	}
	return 0;
}