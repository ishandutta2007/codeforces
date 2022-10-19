#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans(0);
vector<int> E;
vector<bool> was;

void dfs(int v, int i) {
	ans[i].push_back(v);
	was[v] = true;
	if (!was[E[v]])
		dfs(E[v], i);
}

int main() {
	int n;
	cin >> n;
	E.resize(n);
	was.resize(n);
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
		E[v[i].second] = i;
	for (int i = 0; i < n; ++i) {
		if (!was[i]) {
			ans.push_back(vector<int> ());
			dfs(i, (int)ans.size() - 1);
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.size() << ' ';
		for (auto j : i)
			cout << j + 1 << ' ';
		cout << endl;
	}
}