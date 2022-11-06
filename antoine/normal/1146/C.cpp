#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

int dp[101][9];

void f(const int i, const int j, const int depth) {
	if (i == j)
		return;
	assert(depth < 9);
	const int mid = (i + j) / 2;
	for (int k = i; k <= j; ++k)
		dp[k][depth] = k > mid;
	f(i, mid, depth + 1);
	f(mid + 1, j, depth + 1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	f(1, 100, 0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < 9; ++i) {
			vector<int> v[2];
			for (int j = 1; j <= n; ++j)
				v[dp[j][i]].push_back(j);
			if (v[0].empty() || v[1].empty())
				continue;
			cout << v[0].size() << ' ' << v[1].size() << ' ';
			for (int x : v[0])
				cout << x << ' ';
			for (int x : v[1])
				cout << x << ' ';
			cout << endl;

			int res;
			cin >> res;
			ans = max(ans, res);
		}
		cout << "-1 " << ans << endl;
	}
	return 0;
}