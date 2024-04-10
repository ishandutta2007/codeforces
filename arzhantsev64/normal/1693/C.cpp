#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

int n, m;
vector<vector<int>> G;
vector<vector<int>> inv_G;

void solve() {
	cin >> n >> m;
	G = vector<vector<int>> (n);
	inv_G = vector<vector<int>> (n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		inv_G[v].push_back(u);
	}

	set<pair<int, int>> s;
	vector<int> d(n, 1e18);
	d[n - 1] = 0;
	s.insert({0, n - 1});
	while (!s.empty()) {
		auto p = *s.begin();
		s.erase(s.begin());
		int v = p.second;
		for (int to : inv_G[v]) {
			if (d[to] > d[v] + 1) {
				s.erase({d[to], to});
				d[to] = d[v] + 1;
				s.insert({d[to], to});
			}
		}
	}

	vector<int> ord(n);
	for (int i = 0; i < n; ++i)
		ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int a, int b)
	{
	    return d[a] < d[b];
	});

	vector<int> dd(n, 1e18);
	dd[n - 1] = 0;
	for (int _ = 0; _ < 10; ++_) {
		for (int v : ord) {
			vector<int> near;
			for (int to : G[v]) {
				near.push_back(dd[to]);
			}
			sort(near.rbegin(), near.rend());
			int ans = dd[v];
			for (int i = 0; i < near.size(); ++i)
				ans = min(ans, i + 1 + near[i]);
			dd[v] = ans;
		}
	}
	cout << dd[0] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}