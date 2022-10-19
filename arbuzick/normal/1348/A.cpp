#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> st(31);
	st[0] = 1;
	for (int i = 1; i < 31; ++i)
		st[i] = st[i - 1] * 2;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int k1 = 0, k2 = 0;
		k1 += st[n];
		for (int i = 1; i < n / 2; ++i)
			k1 += st[i];
		for (int i = n / 2; i < n; ++i)
			k2 += st[i];
		cout << abs(k1 - k2) << "\n";
	}
	return 0;
}