#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

const int maxn = 4e5 + 42;

vector<int> g[maxn];
int a[maxn];

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	multiset<int> banks;
	for(int i = 0; i < n; i++) {
		banks.insert(a[i]);
	}
	int ans = 1e18;
	for(int i = 0; i < n; i++) {
		int cur = a[i];
		banks.erase(banks.find(a[i]));
		for(auto u: g[i]) {
			banks.erase(banks.find(a[u]));
			cur = max(cur, a[u] + 1);
		}
		if(banks.size()) {
			cur = max(cur, *prev(end(banks)) + 2);
		}
		ans = min(ans, cur);
		banks.insert(a[i]);
		for(auto u: g[i]) {
			banks.insert(a[u]);
		}
	}
	cout << ans << endl;
	return 0;
}