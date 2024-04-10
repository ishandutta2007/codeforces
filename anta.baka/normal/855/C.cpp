#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int n, m, k, x, ans;
vector<int> g[100000];
ll dp[100000][11][3];

void go(int v, int p) {
	dp[v][0][0] = dp[v][0][2] = dp[v][1][1] = 1;
	for(int to : g[v]) {
		if(to == p) continue;
		go(to, v);
		vector<ll> dp0(11, 0), dp1(11, 0), dp2(11, 0);
		for(int sz = x; sz; sz--) {
			for(int sz1 = 0; sz1 < sz; sz1++) {
				dp0[sz] = (dp0[sz] + dp[v][sz - sz1][0] * (dp[to][sz1][0] + dp[to][sz1][1] + dp[to][sz1][2])) % mod;
				dp1[sz] = (dp1[sz] + dp[v][sz - sz1][1] * (dp[to][sz1][0])) % mod;
				dp2[sz] = (dp2[sz] + dp[v][sz - sz1][2] * (dp[to][sz1][0] + dp[to][sz1][2])) % mod;
			}
			dp0[sz] = (dp0[sz] + dp[v][0][0] * (dp[to][sz][0] + dp[to][sz][1] + dp[to][sz][2])) % mod;
			dp2[sz] = (dp2[sz] + dp[v][0][2] * (dp[to][sz][0] + dp[to][sz][2])) % mod;
		}
		dp0[0] = (dp0[0] + dp[v][0][0] * (dp[to][0][0] + dp[to][0][2])) % mod;
		dp2[0] = (dp2[0] + dp[v][0][2] * (dp[to][0][0] + dp[to][0][2])) % mod;
		for(int i = 0; i <= x; i++) {
			dp[v][i][0] = dp0[i];
			dp[v][i][1] = dp1[i];
			dp[v][i][2] = dp2[i];
		}
	}
	for(int sz = 0; sz <= x; sz++) {
		dp[v][sz][0] = dp[v][sz][0] * (k - 1) % mod;
		dp[v][sz][2] = dp[v][sz][2] * (m - k) % mod;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v); g[v].push_back(u);
	}
	cin >> k >> x;
	go(0, -1);
	for(int i = 0; i <= x; i++)
		for(int j = 0; j < 3; j++)
			ans = (ans + dp[0][i][j]) % mod;
	cout << ans;
}