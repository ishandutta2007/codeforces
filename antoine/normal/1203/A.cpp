#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a)
			cin >> x;
		vector<int> b(n);
		iota(b.begin(), b.end(), 1);
		bool ok = false;
		for (int rep = 0; rep < 2; ++rep) {
			reverse(a.begin(), a.end());
			for (int rep = 0; rep < n; ++rep) {
				rotate(a.begin(), a.begin() + 1, a.end());
				if(a == b)
					ok = true;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}