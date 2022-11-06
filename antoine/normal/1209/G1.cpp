#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	assert(!q);
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	map<int, vector<int>> occ;
	for (int i = 0; i < n; ++i)
		occ[a[i]].push_back(i);

	int start = 0, end = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		end = max(end, occ.at(a[i]).back());
		if (end == i) {
			map<int, int> occ;
			int mx = 0;
			for (int i = start; i <= end; ++i)
				mx = max(mx, ++occ[a[i]]);
			ans += (end - start + 1) - mx;
			start = end = i + 1;
		}
	}
	cout << ans;
	return 0;
}