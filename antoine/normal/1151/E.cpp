#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 1e5 + 9;
int a[MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	map<int, vector<int>> mp;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]].push_back(i);
	}

	ll rem = 0, ans = 0;

	for (int x = mp.rbegin()->first; x >= 1; --x) {
		vector<pair<int, int>> v;
		for (int i : mp[x]) {
			v.push_back( { i - 1, i });
			v.push_back( { i, i + 1 });
		}
		assert(is_sorted(v.begin(), v.end()));
		v.erase(unique(v.begin(), v.end()), v.end());
		for (pair<int, int> &p : v)
			if (a[p.first] >= x && a[p.second] >= x) {
				const int y = max(a[p.first], a[p.second]);
				rem += n - y + 1;
			}
		ans += (ll) mp[x].size() * (n - x + 1LL) * x;
		ans -= rem;
		cerr << ans << ' ';
	}
	cout << ans;
	return 0;
}