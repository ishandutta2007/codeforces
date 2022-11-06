#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 3e5 + 9;
set<int> adj[MxN + 9];
int ans[MxN + 9];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}

	map<vector<int>, vector<int>> mp;
	for (int i = 1; i <= n; ++i) {
		mp[vector<int>(adj[i].begin(), adj[i].end())].push_back(i);
		if (mp.size() > 3) {
			cout << -1;
			return 0;
		}
	}
	if (mp.size() != 3) {
		cout << -1;
		return 0;
	}

	for (auto it = mp.begin(); it != mp.end(); ++it)
		for (auto it2 = next(it); it2 != mp.end(); ++it2) {
			const int x = it->second[0];
			for (int y : it2->second)
				if (!adj[x].count(y)) {
					cout << -1;
					return 0;
				}
		}

	for (auto &&e : mp) {
		const int x = e.second[0];
		for (int y : e.second)
			if (adj[x].count(y)) {
				cout << -1;
				return 0;
			}
	}

	for (auto &&e : mp) {
		static int num = 0;
		++num;
		for (int x : e.second)
			ans[x] = num;
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}