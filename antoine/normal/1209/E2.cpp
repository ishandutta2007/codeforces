#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 12;
const int MxM = 2009;

int pre[1 << MxN];
int dp[1 << MxN];

void maxim(int &x, const int y) {
	x = max(x, y);
}

ll f() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (vector<int> &v : a)
		for (int &x : v)
			cin >> x;

	if (m > n) {
		vector<pair<int, int>> v;
		for (int j = 0; j < m; ++j) {
			int mx = INT_MIN;
			for (int i = 0; i < n; ++i)
				mx = max(mx, a[i][j]);
			v.push_back( { -mx, j });
		}
		nth_element(v.begin(), v.begin() + n, v.end());
		vector<vector<int>> b(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				b[i][j] = a[i][v[j].second];
		a = move(b);
		m = n;
	}
	memset(dp, 0, sizeof dp);

	int _cnt = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		++_cnt;
		int mn = mask;
		for (int rep = 0; rep < n; ++rep) {
			mask <<= 1;
			if (mask & (1 << n)) {
				mask ^= 1 << n;
				mask++;
			}
			mn = min(mn, mask);
		}
		pre[mask] = mn;
	}
	assert(_cnt == (1 << n));
	for (int j = m - 1; j >= 0; --j) {
		for (int mask = (1 << n) - 1; mask >= 0; --mask) {
			int &res = dp[mask];
			for (int i = n - 1; i >= 0; --i)
				if (!(mask & (1 << i)))
					res = max(res, a[i][j] + dp[mask | (1 << i)]);
		}
		for (int mask = (1 << n) - 1; mask >= 0; --mask)
			maxim(dp[pre[mask]], dp[mask]);
		for (int mask = (1 << n) - 1; mask >= 0; --mask)
			maxim(dp[mask], dp[pre[mask]]);
	}
	return dp[0];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}