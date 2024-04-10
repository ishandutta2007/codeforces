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

int n;
vector<vector<int>> G;
vector<int> l;
vector<int> r;

pair<int, int> dfs(int v, int p = -1) {
	int have = 0;
	int moves = 0;
	for (int to : G[v]) {
		if (to == p)
			continue;
		auto pp = dfs(to);
		have += pp.first;
		moves += pp.second;
	}
	if (have > r[v])
		have = r[v];
	if (have < l[v]) {
		have = r[v];
		moves += 1;
	}
	return {have, moves};
}

void solve() {
	cin >> n;
	G = vector<vector<int>> (n);
	for (int i = 0; i < n - 1; ++i) {
		int x;
		cin >> x;
		G[x - 1].push_back(i + 1);
	}
	l = vector<int> (n);
	r = vector<int> (n);
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
	}
	auto pp = dfs(0);
	cout << pp.second << '\n';
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