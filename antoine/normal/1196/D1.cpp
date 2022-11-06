#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
	int n, k;
	string s, rgb = "RGB";
	cin >> n >> k >> s;
	vector<int> a(n, 0);

	int ans = n;
	for (int rep = 0; rep < 3; ++rep) {
		rotate(rgb.begin(), rgb.begin() + 1, rgb.end());
		for (int i = 0; i < n; ++i)
			a[i] = s[i] != rgb[i % 3];
		partial_sum(a.begin(), a.end(), a.begin());
		int res = a[k - 1];
		for (int i = 1; i < n - k + 1; ++i)
			res = min(res, a[i + k - 1] - a[i - 1]);
		ans = min(ans, res);
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		f();
	}
	return 0;
}