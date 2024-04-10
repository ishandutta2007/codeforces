#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;

ll answer = 0;
int a[maxn], b[maxn], c[maxn];
vector<int> t[maxn];
int dp[maxn], pd[maxn];

void dfs(int v, int par = -1){
	if (b[v] != c[v]){
		if (b[v] == 0)
			dp[v] ++;
		else
			pd[v] ++;
	}
	for (auto u : t[v]){
		if (u != par){
			a[u] = min(a[u], a[v]);
			dfs(u, v);
			int T = min(dp[v], pd[u]);
			answer += 1ll * T * a[v];
			dp[v] -= T, pd[u] -= T;
			T = min(pd[v], dp[u]);
			answer += 1ll * T * a[v];
			pd[v] -= T, dp[u] -= T;
			dp[v] += dp[u], pd[v] += pd[u];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int v = 1; v <= n; v++)
		cin >> a[v] >> b[v] >> c[v];
	for (int i = 1; i <= n-1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	if (dp[1] + pd[1] > 0)
		return cout << -1 << endl, 0;
	cout << 2ll * answer << endl;
}