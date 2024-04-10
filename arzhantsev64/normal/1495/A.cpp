#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> x;
	vector<int> y;
	while (x.size() != n || y.size() != n) {
		int xx, yy;
		cin >> xx >> yy;
		xx = abs(xx);
		yy = abs(yy);
		if (xx != 0) x.push_back(xx);
		if (yy != 0) y.push_back(yy);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	long double s = 0;
	for (int i = 0; i < n; ++i)
		s += sqrt(x[i]*x[i] + y[i]*y[i]);
	cout.precision(20);
	cout << s << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}