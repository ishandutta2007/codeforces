#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<pair<int,int>> gr[N];
vector<bool> skl(N, false);
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0, u, v, c; i < m; i++) {
		cin >> u >> v >> c;
		u--; v--;
		gr[u].push_back({v, c});
		gr[v].push_back({u, c});
	}
	for(int i = 0, v; i < k; i++) {
		cin >> v; v--;
		skl[v] = true;
	}
	int ans = 2e9;
	for(int i = 0; i < n; i++)
		if(!skl[i])
			for(int j = 0, sz = (int)gr[i].size(); j < sz; j++)
				if(skl[gr[i][j].first])
					ans = min(ans, gr[i][j].second);
	if(ans == 2e9) cout << -1;
	else cout << ans;
	return 0;
}