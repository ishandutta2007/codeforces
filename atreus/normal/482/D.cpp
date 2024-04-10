#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int dp[maxn], pd[maxn];
vector<int> t[maxn];

void dfs(int v){
	if (t[v].empty()){
		dp[v] = 1;
		return;
	}
	int m = t[v].size();
	dp[v] = 1;
	pd[v] = 0;
	for (int i = 0; i < m; i++){
		int u = t[v][i];
		dfs(u);
		int DP = dp[v];
		int PD = pd[v];
		dp[v] = (1ll * DP * (1 + pd[u]) + 1ll * PD * dp[u]) % mod;
		pd[v] = (1ll * DP * dp[u] + 1ll * PD * (1 + pd[u])) % mod;
	}
	int dynamic = dp[v];
	int pynamic = pd[v];
	dp[v] = 1;
	pd[v] = 0;
	for (int i = m - 1; i >= 0; i--){
		int u = t[v][i];
		int DP = dp[v];
		int PD = pd[v];
		dp[v] = (1ll * DP * (1 + pd[u]) + 1ll * PD * dp[u]) % mod;
		pd[v] = (1ll * DP * dp[u] + 1ll * PD * (1 + pd[u])) % mod;
	}
//	if (v == 1)
//		cout << "# " << dynamic << " " << dp[v] << endl;
	dp[v] = (dp[v] + dynamic) % mod;
	pd[v] = (pd[v] + pynamic) % mod;
	int q = 1;
	for (int i = 0; i < m; i++){
		int u = t[v][i];
		q = 1ll * q * (1 + pd[u]) % mod;
	}
	dp[v] = (dp[v] - q + mod) % mod;
	int dy = 1;
	int py = 0;
	for (int i = 0; i < m; i++){
		int u = t[v][i];
		int Dp = (dy + 1ll * py * dp[u]) % mod;
		int Pd = (py + 1ll * dy * dp[u]) % mod;
		dy = Dp;
		py = Pd;
	}
	pd[v] = (pd[v] - py + mod) % mod;
//	cout << v << " -> " << dp[v] << " " << pd[v] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++){
		int p;
		cin >> p;
		t[p].push_back(i);
	}
	dfs(1);
	cout << (dp[1] + pd[1]) % mod << endl;
}