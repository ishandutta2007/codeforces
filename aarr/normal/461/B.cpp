#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;

long long dp[N][3];
int c[N];
vector <int> chld[N];
int par[N];

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}

void dfs(int v) {
	dp[v][1] = c[v];
	dp[v][0] = 1 - c[v];
	long long p = 1;
	for (auto u : chld[v]) {
		dfs(u);
		p *= dp[u][1];
		p %= mod;
		dp[v][1] *= (dp[u][0] + dp[u][1]);
		dp[v][0] *= (dp[u][0] + dp[u][1]);
		dp[v][1] %= mod;
		dp[v][0] %= mod;
	}
	for (auto u : chld[v]) {
		if (!c[v]) {
			long long x = 1ll * dp[v][0] * po(dp[u][1] + dp[u][0], mod - 2);
			x %= mod;
			x *= dp[u][1];
			x %= mod;
//			cout << "72 " << v << " " << u << " " << x << endl;
			dp[v][1] += x;
		}
	}
/*	if (!c[v]) {
		dp[v][0] += p;
		dp[v][1] += 1ll * p * chld[v].size();
	}*/
	dp[v][0] %= mod;
	dp[v][1] %= mod;
//	cout << "73 " << v << " " << dp[v][0] << " " << dp[v][1] << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> par[i];
		chld[par[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	dfs(0);
	cout << dp[0][1];
	return 0;
}