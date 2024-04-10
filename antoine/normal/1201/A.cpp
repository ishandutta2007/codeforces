#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<map<char, int>> occ(m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			++occ[j][c];
		}

	ll ans = 0;
	for (int i = 0; i < m; ++i) {

		int mx = 0;
		for (auto e : occ[i])
			mx = max(mx, e.second);

		ll x;
		cin >> x;

		ans += x * mx;
	}
	cout << ans;
	return 0;
}