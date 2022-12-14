/***
  * Virtual Contest: Forethought Future Cup - Elimination Round
***/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
const int mod = 998244353;

int dp[maxn], pd[maxn];
vector<int> t[maxn];

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

void dfs(int v){
	dp[v] = 1;
	pd[v] = 1;
	if (t[v].empty())
		return;
	int muldp = 1;
	for (auto u : t[v]){
		dfs(u);
		dp[v] = 1ll * dp[v] * (dp[u] + pd[u]) % mod;
		muldp = 1ll * muldp * dp[u] % mod;
	}
	for (auto u : t[v]){
		dp[v] -= 1ll * muldp * power(dp[u], mod - 2) % mod * pd[u] % mod;
		if (dp[v] < 0)
			dp[v] += mod;
	}
	pd[v] = (dp[v] - muldp + mod) % mod;
	for (auto u : t[v]){
		pd[v] += 1ll * muldp * power(dp[u], mod - 2) % mod * pd[u] % mod;
		if (pd[v] >= mod)
			pd[v] -= mod;
	}
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
	cout << dp[1] << endl;
}