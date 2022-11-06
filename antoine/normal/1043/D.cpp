#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll P2(ll x) {
	return x * (x + 1) / 2;
}
int n, m;
int a[10][(int) 1e5 + 9];
int dp[(int) 1e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	map<pair<int, int>, int> occ;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	for (int i = 0; i < m; ++i)
		for (int j = 0; j + 1 < n; ++j)
			++occ[ { a[i][j], a[i][j + 1] }];

	for (int i = 0; i + 1 < n; ++i)
		dp[i] = occ[ { a[0][i], a[0][i + 1] }] == m;

	ll ans = n;
	for (int i = 0; i + 1 < n; ++i) {
		if (!dp[i])
			continue;
		int j = i;
		while (dp[j + 1])
			++j;

		ans += P2(j - i + 1);

		i = j;
	}
	cout << ans;
	return 0;
}