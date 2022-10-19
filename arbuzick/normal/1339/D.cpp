#include<bits/stdc++.h>
using namespace std;
int o = -1;
vector<vector<int>> a;
int dfs(int v, int pr, int d) {
	int m = 0;
	int ans = 0;
	if (a[v].size() == 1) {
		if (o == -1)
			o = d % 2;
		else if (o != d % 2)
			o = 3;
	}
	for (int i = 0; i < a[v].size(); ++i)
		if (a[v][i] != pr) {
			ans = ans + dfs(a[v][i], v, d + 1);
			if (a[a[v][i]].size() == 1)
				m += 1;
		}
	if (m == 0)
		return ans;
	else
		return ans + m - 1;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	a = vector<vector<int>>(n);
	int k = -1;
	for (int i = 0; i < n - 1; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		a[v1 - 1].push_back(v2 - 1);
		a[v2 - 1].push_back(v1 - 1);
		if (a[v1 - 1].size() > 1)
			k = v1 - 1;
		if (a[v2 - 1].size() > 1)
			k = v2 - 1;
	}
	int ans = dfs(k, -1, 0);
	if (o == 3)
		cout << 3 << ' ';
	else
		cout << 1 << ' ';
	cout << n - 1 - ans << endl;
	return 0;
}