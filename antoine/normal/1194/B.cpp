#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (string &s : grid)
		cin >> s;

	vector<int> a(n, 0), b(m, 0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] == '*')
				++a[i], ++b[j];

	int ans = n * m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ans = min(ans, n - a[i] + m - b[j] - (grid[i][j] == '.'));
	return ans;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int Q;
	cin >> Q;
	while (Q--)
		cout << f() << '\n';
	return 0;
}