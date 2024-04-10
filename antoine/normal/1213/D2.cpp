#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	map<int, vector<int>> mp;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		int j = 0;
		do {
			mp[x].push_back(j);
			j++;
			x >>= 1;
		} while (x);
	}
	int ans = (int) 1e9;
	for (auto &&e : mp) {
		vector<int> &v = e.second;
		if ((int) v.size() < k)
			continue;
		sort(v.begin(), v.end());
		ans = min(ans, accumulate(v.begin(), v.begin() + k, 0));
	}
	cout << ans;
	return 0;
}