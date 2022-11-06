#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
ll dp[MxN + 9][3];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	map<int, pair<int, int>> mp;
	set<int> cols;

	{
		int n, m, k, q;
		cin >> n >> m >> k >> q;

		for (int i = 0; i <= k; ++i) {
			int r = 1, c = 1;
			if (i < k)
				cin >> r >> c;
			if (!mp.count(r))
				mp[r]= {c, c};
				else {
					pair<int, int> &p = mp[r];
					p.first= min(p.first, c);
					p.second= max(p.second, c);
				}
			}

		for (int i = 0; i < q; ++i) {
			int x;
			cin >> x;
			cols.insert(x);
		}
	}

	const ll Inf = (ll) 1e18 + 9;

	auto f = [&](const int r1, const int c1, const int r2, const int c2) {
		ll res= Inf;

		auto it = cols.lower_bound(c1);
		if(it != cols.end()) {
			res = min(res, llabs(c1 - *it) + llabs(c2 - *it) + llabs(r1 - r2));
		}
		if(it != cols.begin()) {
			--it;
			res = min(res, llabs(c1 - *it) + llabs(c2 - *it) + llabs(r1 - r2));
		}
		return res;
	};

	for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
		for (int j = 0; j < 2; ++j) {
			ll &res = dp[it->first][j] = Inf;
			const ll diff = it->second.second - it->second.first;
			if (it == mp.rbegin())
				res = diff;
			else if (j == 0) {
				ll opt1 = f(it->first, it->second.second, prev(it)->first, prev(it)->second.first) + dp[prev(it)->first][0];
				ll opt2 = f(it->first, it->second.second, prev(it)->first, prev(it)->second.second) + dp[prev(it)->first][1];
				res = diff + min(opt1, opt2);
			} else {
				assert(j == 1);
				ll opt1 = f(it->first, it->second.first, prev(it)->first, prev(it)->second.first) + dp[prev(it)->first][0];
				ll opt2 = f(it->first, it->second.first, prev(it)->first, prev(it)->second.second) + dp[prev(it)->first][1];
				res = diff + min(opt1, opt2);
			}
		}
	}

	cout << dp[1][0];

	return 0;
}