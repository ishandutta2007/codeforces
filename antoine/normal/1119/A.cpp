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

	int ans = 0;
	for (int rep = 0; rep < 2; ++rep) {
		reverse(a.begin(), a.end());
		for (int i = 0; i < n; ++i)
			if (a[i] != a.back())
				ans = max(ans, n - 1 - i);
	}
	cout << ans;
	return 0;
}