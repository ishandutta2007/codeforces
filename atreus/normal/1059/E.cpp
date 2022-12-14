#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;
const int maxl = 22;

int dp[maxn], pd[maxn], up[maxn], par[maxn][maxl];
ll sum[maxn][maxl];
vector<int> t[maxn];

void dfs(int v){
	int mxm = 0;
	for (auto u : t[v]){
		dfs(u);
		dp[v] += dp[u];
		mxm = max(mxm, pd[u] - 1);
	}
	if (mxm == 0){
		dp[v] ++;
		pd[v] = up[v];
	}
	else{
		pd[v] = mxm;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, L;
	ll S;
	cin >> n >> L >> S;
	for (int v = 1; v <= n; v++)
		cin >> sum[v][0];

	memset(par, -1, sizeof par);
	for (int v = 2; v <= n; v++){
		cin >> par[v][0];
		t[par[v][0]].push_back(v);
		for (int j = 1; j <= 20 and par[v][j - 1] != -1; j++){
			par[v][j] = par[par[v][j - 1]][j - 1];
			sum[v][j] = sum[v][j - 1] + sum[par[v][j - 1]][j - 1];
		}
		int now = v, cnt = 0;
		ll s = 0;
		for (int j = 20; j >= 0; j--){
			if (par[now][j] == -1)
				continue;
			if (sum[now][j] + s <= S){
				s += sum[now][j];
				now = par[now][j];
				cnt += (1 << j);
			}
		}
		if (now == 1 and sum[1][0] + s <= S)
			cnt ++;
		up[v] = min(L, cnt);
	}
	for (int i = 1; i <= n; i++)
		if (sum[i][0] > S)
			return cout << "-1\n", 0;
	dfs(1);
	cout << dp[1] << endl;
}