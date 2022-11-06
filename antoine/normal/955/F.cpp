#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;
typedef long long ll;

int n;
const int MaxN = 3e5;
vector<int> adj[MaxN];
vector<int> prec[MaxN];

void dfs(const int u, const int p) {
	prec[u] = { 1, n };
	adj[u].erase(remove(adj[u].begin(), adj[u].end(), p), adj[u].end());
	for (auto &&v : adj[u]) {
		dfs(v, u);
		prec[u][0] = max(prec[u][0], 1 + prec[v][0]);
	}

	for (int i = 2;; ++i) {
		int lo = 1;
		int hi = adj[u].size();
		while (lo < hi) {
			int mid = (lo + hi + 1) >> 1;
			int count = 0;
			for (auto &&v : adj[u])
				count += i <= prec[v].size() && prec[v][i - 1] >= mid;
			if (count >= mid)
				lo = mid;
			else
				hi = mid - 1;
		}
		if (lo <= 1)
			break;
		prec[u].push_back(lo);
	}
}

void dfs2(const int u, ll &ans) {
	for (auto &&v : adj[u]) {
		dfs2(v, ans);
		if (prec[u].size() < prec[v].size())
			prec[u].resize(prec[v].size(), 0);
		for (int i = 2; i < prec[v].size(); ++i)
			prec[u][i] = max(prec[u][i], prec[v][i]);
	}
	ans -= prec[u].size() - 1;
	for (auto &&x : prec[u])
		ans += x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, -1);
	ll ans = 0;
	dfs2(0, ans);
	cout << ans;
	return 0;
}