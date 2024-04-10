#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int maxn = 4000 + 10;
const ll INF = 4e18;

int m, a[maxn];
int newInt = 1;
ll dp[maxn][maxn];
int sz[maxn];

int solve(int l, int r) {
	if (l == r) {
		dp[0][0] = 0;
		return 0;
	}
	int v = newInt++;
	dp[v][0] = 0;
	if (l + 1 == r) {
		dp[v][1] = 1LL * (m - 1) * a[l];
		sz[v] = 1;
		return v;
	}
	int idx = l;
	for (int i = l; i < r; i++)
		if (a[i] < a[idx])
			idx = i;
	int lc = solve(l, idx);
	int rc = solve(idx+1, r);

	int sz1 = sz[lc], sz2 = sz[rc];
	for (int i = 1; i <= sz1 + 1; i++)
		dp[v][i] = max(dp[lc][i], dp[lc][i - 1] + 1LL * (m - (2 * i - 1)) * a[idx]);
	for (int i = sz1 + 1; i >= 0; i--)
		for (int j = sz2; j >= 0; j--)
			dp[v][i + j] = max(dp[v][i + j], dp[v][i] + dp[rc][j] - 2LL * i * j * a[idx]);
	sz[v] = sz1 + sz2 + 1;
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(dp, -63, sizeof dp);
	solve(1, n + 1);
	cout << dp[1][m] << '\n';
}