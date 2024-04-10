#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << (n * m - 1) / 2 + 1 << "\n";
	}
	return 0;
}