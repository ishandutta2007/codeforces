#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int Inf = (int) 1e7 + 9;
int dist[101][101];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			char c;
			cin >> c;
			dist[i][j] = i == j ? 0 : c == '1' ? 1 : Inf;
		}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int m;
	cin >> m;
	vector<int> a(m);
	for (int &x : a)
		cin >> x;
	vector<int> dp(m, Inf);
	dp[m - 1] = 1;
	for (int i = m - 2; i >= 0; --i) {
		for (int j = min(m - 1, i + 105);; --j) {
			assert(j > i);
			if (dist[a[i]][a[j]] == j - i) {
				dp[i] = 1 + dp[j];
				break;
			}
		}
	}
	cout << dp[0] << '\n' << a[0];
	for (int i = 0; i < m - 1;) {
		for (int j = min(m - 1, i + 105);; --j) {
			assert(j > i);
			if (dist[a[i]][a[j]] == j - i) {
				cout << ' ' << a[j];
				i = j;
				break;
			}
		}
	}
	return 0;
}