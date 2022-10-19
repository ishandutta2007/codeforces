#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve() {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int imin = -1;
	int minn = 1e18;
	int imax = -1;
	int maxx = -1e18;

	for(int i = 0; i < n; ++i) {
		if (v[i] < minn) {
			minn = v[i];
			imin = i;
		}
		if (v[i] > maxx) {
			maxx = v[i];
			imax = i;
		}
	}

	cout << imin + 1 << ' ' << imax + 1 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}