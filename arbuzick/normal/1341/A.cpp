#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		if (n * (a - b) > c + d)
			cout << "NO" << endl;
		else if (n * (a + b) < c - d)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}