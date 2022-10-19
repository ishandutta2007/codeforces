#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		set<int> b;
		for (int i = 0; i < n; ++i) {
			int x = (i + a[i % n]) % n;
			if (x < 0) {
				x += n;
			}
			b.insert(x);
		}
		if (b.size() == n)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}