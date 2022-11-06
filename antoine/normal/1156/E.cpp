#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct DSU {

	vector<int> rank;
	vector<int> parent;

	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};
bool compBySecond(const pii &p1, const pii &p2) {
	return p1.second < p2.second;
}

set<int> merge(set<int> &s1, set<int> &s2) {
	if (s1.size() > s2.size())
		swap(s1, s2);
	for (int x : s1)
		s2.insert(x);
	return move(s2);
}

int cnt(const set<int> &s1, const set<int> &s2, const int mx) {
	if (s1.size() > s2.size())
		return cnt(s2, s1, mx);

	int res = 0;
	for (int x : s1)
		res += s2.count(mx - x);
	return res;
}

inline void merge(int u, int v, const int mx, DSU &dsu, vector<set<int>> &dp, ll &ans) {
	u = dsu.find(u);
	v = dsu.find(v);
	if (u == v)
		return;

	ans += cnt(dp[u], dp[v], mx);
	set<int> s = merge(dp[u], dp[v]);
	dsu.merge(u, v);
	u = dsu.find(u);
	dp[u] = move(s);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	vector<pair<int, int>> aPairs;
	for (int i = 0; i < n; ++i)
		aPairs.push_back( { a[i], i });
	sort(aPairs.begin(), aPairs.end());



	DSU dsu(n);

	vector<set<int>> dp;

	for (int i = 0; i < n; ++i)
		dp.push_back( { a[i] });


	ll ans = 0;
	for (const pii aPair : aPairs) {
		const int i = aPair.second;
		const int val = a[i];
		if (i > 0 && a[i] >= a[i - 1])
			merge(i - 1, i, val, dsu, dp, ans);

		if (i + 1 < n && a[i] >= a[i + 1])
			merge(i, i + 1, val, dsu, dp, ans);
	}


	cout << ans;

	return 0;
}