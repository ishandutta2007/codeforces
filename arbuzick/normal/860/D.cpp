#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
void dfs(int v, vector<vector<pair<int, pair<int, int>>>>& a, vector<pair<int, pair<int, int>>>& ans, vector<int>&used, int par, int parind) {
	used[v] = 1;
	for (int i = 0; i < a[v].size(); ++i)
		if (used[a[v][i].first] == 0)
			dfs(a[v][i].first, a, ans, used, v, i);
	pair<int, pair<int, int>> ans1 = { 0, {v, 0} };
	int ind = 0;
	for(int i = 0; i < a[v].size(); ++i)
		if (a[v][i].second.first == 0&&a[v][i].first != par) {
			if (ind == 0) {
				ans1.first = a[v][i].first;
				a[v][i].second.first = 1;
				a[a[v][i].first][a[v][i].second.second].second.first = 1;
				ind = 1;
			}
			else {
				ans1.second.second = a[v][i].first;
				a[v][i].second.first = 1;
				a[a[v][i].first][a[v][i].second.second].second.first = 1;
				ans.push_back(ans1);
				ind = 0;	
			}
		}
	if (ind == 1&&par != -1) {
		ans1.second.second = par;
		a[par][parind].second.first = 1;
		a[v][a[par][parind].second.second].second.first = 1;
		ans.push_back(ans1);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, pair<int, int>>>> a(n);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		a[v1 - 1].push_back({ v2 - 1, {0, a[v2 - 1].size()} });
		a[v2 - 1].push_back({ v1 - 1, {0, a[v1-1].size() - 1} });
	}
	vector<pair<int, pair<int, int>>> ans;
	vector<int> used(n);
	for (int i = 0; i < n; ++i)
		used[i] = 0;
	for (int i = 0; i < n; ++i)
		if (used[i] == 0)
			dfs(i, a, ans, used, -1, -1);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].first+1 << " " << ans[i].second.first+1 << " " << ans[i].second.second+1 << endl;
	return 0;
}