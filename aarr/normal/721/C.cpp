#include <iostream>
#include <vector>
using namespace std;

const int N = 5005;
const int inf = 1000 * 1000 * 1000 + 7;

int dp[N][N];
int par[N][N];
vector <pair <int, int> > adjr[N];
vector <int> ans;

int main() {
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjr[v].push_back({u, w});
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = inf;
		}
	}
	dp[1][1] = 0;
	for (int j = 2; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < adjr[i].size(); k++) {
				int u = adjr[i][k].first, w = adjr[i][k].second;
				if (dp[u][j - 1] + w < dp[i][j]) {
					dp[i][j] = dp[u][j - 1] + w;
					par[i][j] = u;
				}
			}
//			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	int k = 1, u = n;
	for (int j = 1; j <= n; j++) {
		if (dp[n][j] <= t) {
			k = j;
		}
	}
	for (int j = k; j; j--) {
		ans.push_back(u);
		u = par[u][j];
	}
	cout << k << endl;
	for (int i  = (int) ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	return 0;
}