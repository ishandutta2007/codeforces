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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		set<int> b;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			b.insert(a[i]);
		}
		if (b.size() > k)
			cout << -1 << "\n";
		else {
			if (b.size() < k) {
				for (int i = 1; i <= n; ++i)
					if (b.count(i) == 0&&b.size() < k)
						b.insert(i);
			}
			cout << n * k << "\n";
			auto it = b.begin();
			for (int i = 0; i < n * k; ++i) {
				cout << *it << ' ';
				auto it2 = b.end();
				it++;
				if (it == it2) {
					it = b.begin();
				}
			}
			cout << "\n";
		}
	}
	return 0;
}