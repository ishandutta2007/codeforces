#include <bits/stdc++.h>
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;
#define int long long
int k, n;
vector<pair<int, int> > adj[200010];
int sz[200020], seen[200020], upto;
int dfsfindsz(int a) {
	if (seen[a] == upto) return 0;
	seen[a] = upto;
	sz[a] = 0;
	for (auto b : adj[a]) {
		sz[a] += dfsfindsz(b.first);
	}
	return ++sz[a];
}
int ans;
int dfs1(int a) {
	if (seen[a] == upto) return 0;
	seen[a] = upto;
	for (auto b : adj[a]) {
		if (dfs1(b.first)) {
			ans += b.second;
		}
	}
	return sz[a]%2;
}
int dfsfindcentroid(int a) {
	seen[a] = upto;
	pair<int, int> biggestchild = { -1, -1 };
	for (auto b : adj[a]) {
		if (seen[b.first] != upto) {
			biggestchild = max(biggestchild, { sz[b.first], b.first });
		}
	}
	if (biggestchild.first <= k) {
		return a;
	}
	return dfsfindcentroid(biggestchild.second);
}
int dfs2(int a) {
	if (seen[a] == upto) return 0;
	seen[a] = upto;
	for (auto b : adj[a]) {
		int val = dfs2(b.first);
		D("adding %lld %lld\n", val, b.second);
		ans += val*b.second;
	}
	return sz[a];
}
void solve() {
	ans = 0;
	scanf("%lld", &k);
	n = 2*k;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	upto++;
	dfsfindsz(1);
	upto++;
	dfs1(1);
	printf("%lld ", ans);
	ans = 0;
	upto++;
	int c = dfsfindcentroid(1);
	D("centroid %lld\n", c);
	upto++;
	dfsfindsz(c);
	upto++;
	dfs2(c);
	printf("%lld\n", ans);

}
#undef int
int main() {
	#define int long long
	int t;
	scanf("%lld", &t);
	for (int i = 0; i < t; i++) solve();
}