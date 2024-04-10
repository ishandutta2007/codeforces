#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e5 + 10;
const int inf = 3e5;

vector<int> t[maxn];
int sz[maxn], h[maxn];
int dp[maxn], pd[maxn];

void dfs(int v, int par = -1){
	if ((int)t[v].size() == 1 and par != -1){
		dp[v] = pd[v] = 1;
		return;
	}
	for (auto u : t[v])
		if (u != par)
			dfs(u, v);
	if (h[v] == 0){
		int mnm = inf;
		for (auto u : t[v]){
			if (u != par){
				dp[v] += sz[u];
				mnm = min(mnm, sz[u] - dp[u]);
				
				pd[v] += pd[u];
			}
		}
		dp[v] -= mnm;
	}
	else{
		pd[v] = inf;
		for (auto u : t[v]){
			if (u != par){
				dp[v] += dp[u] - 1;
				pd[v] = min(pd[v], pd[u]);
			}
		}
		dp[v] ++;
	}
}

void dfsinit(int v, int par = -1){
	if ((int)t[v].size() == 1 and par != -1)
		sz[v] = 1;
	for (auto u : t[v]){
		if (u != par){
			h[u] = h[v] ^ 1;
			dfsinit(u, v);
			sz[v] += sz[u];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 1)
		return cout << 1 << " " << 1 << endl, 0;
	for (int i = 1; i <= n-1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfsinit(1);
	dfs(1);
	cout << dp[1] << " " << pd[1];
}