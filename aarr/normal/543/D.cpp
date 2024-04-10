#include <iostream>
#include <vector>
using namespace std;


const int N = 200 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;

int par[N];
vector <int> chld[N];
long long dp[N];
long long ans[N];
long long dp2[N];
vector <long long> pre[N];
vector <long long> suf[N];
void dfs1(int v) {
	dp[v] = 1;
	for (int i = 0; i < chld[v].size(); i++) {
		int u = chld[v][i];
		dfs1(u);
		dp[v] *= dp[u] + 1;
		dp[v] %= mod;
		pre[v][i] = dp[v];
	//	if (i > 0) {
	//		pre[v][i] *= pre[v][i - 1];
	//		pre[v][i] %= mod;
	//	}
	}
	for (int i = (int) chld[v].size() - 1; i >= 0; i--) {
		int u = chld[v][i];
		suf[v][i] = suf[v][i + 1] * (dp[u] + 1);
		suf[v][i] %= mod;
	}
}
int po(int x, int y) {
	if (y == 0)
		return 1;
	long long ans = po(x, y / 2);
	ans *= ans;
//	ans %= mod;
	if (y % 2 == 1) {
		ans *= x;
//		ans %= mod;
	}
	return ans;
}
void dfs2(int v) {
	if (v == 1) {
		ans[v] = dp[v];
		dp2[v] = 1;
	}
/*	else {
		ans[v] = ans[par[v]];
		
//		ans[v] *= po(dp[v] + 1, mod - 2);
		ans[v] /= dp[v] + 1;
		ans[v]++;
//		ans[v] %= mod;
		for (auto u : chld[v]) {
			ans[v] *= dp[u] + 1;
			ans[v] %= mod;
		}
	}*/
	for (int i = 0; i < chld[v].size(); i++) {
		int u = chld[v][i];
		dp2[u] = dp2[v];
		dp2[u] *= suf[v][i + 1];
		dp2[u] %= mod;
		if (i > 0) {
			dp2[u] *= pre[v][i - 1];
			dp2[u] %= mod;
		}
		dp2[u]++;
		dfs2(u);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		chld[par[i]].push_back(i);
		pre[par[i]].push_back(0);
		suf[par[i]].push_back(0);
	}
	for (int i = 1; i <= n; i++) {
		suf[i].push_back(1);
	}
	dfs1(1);
	dfs2(1);
//	cout << pre[1][0] << endl;
	for (int i = 1; i <= n; i++) {
		cout << 1ll * dp[i] * dp2[i] % mod << " ";
	}
	return 0;
}