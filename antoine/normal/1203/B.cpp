#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool f() {

	int n;
	cin >> n;
	vector<ll> a(4 * n);
	for (ll &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	const ll area = a[0] * a.back();

	for (int i = 0, j = 4 * n - 1; i < j; i += 2, j -= 2)
		if (a[i] != a[i + 1] || a[j] != a[j - 1] || a[i] * a[j] != area)
			return false;

	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		cout << (f() ? "YES" : "NO") << '\n';
	}
	return 0;
}