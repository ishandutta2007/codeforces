#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++a[x - 1];
	}
	sort(a.begin(), a.end());
	for (int i = n - 2; i >= 0; --i)
		a[i] = min(a[i], a[i + 1] - 1);

	ll ans = 0;
	for (int &x : a)
		ans += max(0, x);
	return ans;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--)
		cout << f() << '\n';
	return 0;
}