#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 0));
	vector<vector<int>> b(n, vector<int>(m, 0));
	for (vector<int> &v : a)
		for (int &x : v)
			cin >> x;

vector<pair<int, int>> res;
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
			if (a[i][j] && a[i][j - 1] && a[i - 1][j] && a[i - 1][j - 1]) {
				b[i][j] = b[i][j - 1] = b[i - 1][j] = b[i - 1][j - 1] = 1;
				res.push_back({i, j});
			}
	if(a != b)
		cout << -1;
	else {
		cout << res.size() << '\n';
		for(auto p : res)
			cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}