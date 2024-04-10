#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
vector<int> adj[MxN + 9];
int dp[MxN + 9];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int &x : a)
		cin >> x;

	ll curr = 0;
	for (int i = 0; i + 1 < m; ++i) {
		int u = a[i];
		int v = a[i + 1];
		if (u == v)
			continue;
		if (u > v)
			swap(u, v);
		curr += v - u;
		adj[u].push_back(v);
		adj[v].push_back(u);
		dp[u + 1]++;
		dp[v]--;
	}
	partial_sum(dp, dp + MxN, dp);
	for (int i = 1; i <= n; ++i) {
		ll temp = curr - dp[i];
		for (int x : adj[i])
			temp += -abs(x - i) + (x < i ? x + 1 : x) - 1;
		cout << temp << ' ';
	}
	return 0;
}