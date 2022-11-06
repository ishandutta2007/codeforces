#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	int ans = n;
	set<int> s1;
	for (int i = 0; i < n; ++i) {
		set<int> s2 = s1;
		for (int j = n - 1; j >= i - 1; --j) {
			ans = min(ans, j - i + 1);
			if (s2.count(a[j]))
				break;
			s2.insert(a[j]);

		}
		if (s1.count(a[i]))
			break;
		s1.insert(a[i]);
	}
	cout << ans;
	return 0;
}