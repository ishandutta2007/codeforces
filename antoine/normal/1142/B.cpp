#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<int> perm(n);
	for (int &x : perm) {
		cin >> x;
		--x;
	}

	vector<int> posPerm(n);
	for (int i = 0; i < n; ++i)
		posPerm[perm[i]] = i;

	vector<int> a(m);
	for (int &x : a) {
		cin >> x;
		--x;
	}

	vector<vector<int>> succ(m);

	{
		map<int, int> mp;
		for (int i = m - 1; i >= 0; --i) {
			auto it = mp.find(perm[(posPerm[a[i]] + 1) % n]);
			if (it != mp.end()) {
				succ[i].push_back(it->second);
				for (int j = 1;; ++j) {
					const int u = succ[i][j - 1];
					if (j - 1 >= (int) succ[u].size())
						break;
					succ[i].push_back(succ[u][j - 1]);
				}
			}
			//cerr << succ[i].size() << endl;
			mp[a[i]] = i;
		}
	}

	vector<int> dp(m, 0);
	for (int i = 0; i < m; ++i) {
		int diff = n - 1;
		int u = i;

		for (int i = 0; diff; ++i)
			if (diff & (1 << i)) {
				if (i >= (int) succ[u].size())
					break;
				diff ^= 1 << i;
				u = succ[u][i];
			}

		dp[i] = diff ? m : u;
	}
	for (int i = m - 2; i >= 0; --i)
		dp[i] = min(dp[i], dp[i + 1]);

	// for (int i = 0; i < m; ++i)
	// 	cerr << dp[i] << ' ';

	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		cout << (dp[l] <= r);
	}
	return 0;
}