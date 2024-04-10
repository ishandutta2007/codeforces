#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<pair<int, int>> ans[1009];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
		ans[i].push_back({i, i});
	for(int row = 1000; m--; row++) {
		int u, v;
		cin >> u >> v;
		ans[u].push_back({row, u});
		ans[v].push_back({row, v});
	}
	for(int i = 1; i <= n; ++i) {
		cout << ans[i].size() << '\n';
		for(auto &&x : ans[i])
			cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}