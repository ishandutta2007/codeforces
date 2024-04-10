#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	int n;
   	cin >> n;
   	vector <string> a(n);
   	for (int i = 0; i < n; i++) {
   		cin >> a[i];
   	}
   	int m;
   	cin >> m;
   	vector <int> p(m);
   	for (auto &c : p) {
   		cin >> c;
   		c--;
   	}
   	vector <vector<int>> g(n, vector<int> (n, INF));
   	for (int i = 0; i < n; i++) {
   		for (int j = 0; j < n; j++) {
   			if (a[i][j] == '0') {
   				continue;
   			}
   			g[i][j] = a[i][j] - '0';
   		}
   	}
   	for (int k = 0; k < n; k++) {
   		for (int i = 0; i < n; i++) {
   			for (int j = 0; j < n; j++) {
   				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
   			}
   		}
   	}
   	vector <int> dp(m, INF);
   	vector <int> par(m, -1);
   	vector <int> last(n, -1);
   	dp[0] = 1;
   	last[p[0]] = 0;
   	for (int i = 1; i < m; i++) {
   		for (int j = 0; j < n; j++) {
   			if (last[j] == -1 || p[i] == j) {
   				continue;
   			}
   			if (i - last[j] != g[j][p[i]]) {
   				continue;
   			}
   			if (dp[last[j]] + 1 < dp[i]) {
   				dp[i] = dp[last[j]] + 1;
   				par[i] = last[j];
   			}
   		}
   		last[p[i]] = i;
   	}
   	cout << dp[m - 1] << "\n";
   	vector <int> ans;
   	int now = m - 1;
   	while (now != -1) {
   		ans.pb(p[now]);
   		now = par[now];
   	}
   	reverse(ans.begin(), ans.end());
   	for (auto &c : ans) {
   		cout << c + 1 << " ";
   	}
    return 0;
}