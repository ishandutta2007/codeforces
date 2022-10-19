#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> m(n);
	for (int& mm : m) cin >> mm;
	vector<int> pref_max(n);
	pref_max[0] = m[0] + 1;
	for (int i = 1; i < n; ++i)
		pref_max[i] = max(pref_max[i - 1], m[i] + 1);
	int ans = 0;
	int cur = pref_max.back();
	for (int i = n - 1; i >= 0; --i) {
		cur = max(cur - 1, pref_max[i]);
		ans += (cur - (m[i] + 1));
	}
	cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
	return 0;
}