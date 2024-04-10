#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> a(2, vector<int>(n));
	for (vector<int> &v : a)
		for (int &x : v)
			cin >> x;

	vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));

	for (int i = n - 1; i >= 0; --i)
		for (int j = 0; j < 2; ++j) {
			dp[j][i] = max(dp[j][i + 1], a[j][i] + dp[!j][i + 1]);
		}
	cout << max(dp[0][0], dp[1][0]);
	return 0;
}