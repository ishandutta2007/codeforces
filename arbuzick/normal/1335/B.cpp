#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(30);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n, a, b;
		cin >> n >> a >> b;
		for (int i = 0; i < n; ++i)
			cout << char('a' + i % b);
		cout << endl;
	}
	return 0;
}