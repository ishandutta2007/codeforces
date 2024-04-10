#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 3e5 + 10;

ll a[maxn];
vector <int> t[maxn];
ll dp[maxn], pd[maxn];
pair <int, ll> ans[maxn];

void DFS(int v, int par = -1){
	ans[v].second = a[v];
	for (auto u : t[v]){
		if (u == par)
			continue;
		DFS(u, v);
		ans[v].first += ans[u].first;
		if (ans[u].second > 0)
			ans[v].second += ans[u].second;
	}
	if (ans[v].second == dp[1]){
		ans[v].first ++;
		ans[v].second = 0;
	}
}

void dfs(int v, int par = -1){
	pd[v] = dp[v] = a[v];
	for (auto u : t[v]){
		if (u == par)
			continue;
		dfs(u, v);
		dp[v] = max(dp[v], dp[u]);
		if (pd[u] > 0)
			pd[v] += pd[u];
	}
	dp[v] = max(dp[v], pd[v]);
}

int main(){
	ios_base::sync_with_stdio(false);
	memset (dp, -63, sizeof dp);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].PB(u);
		t[u].PB(v);
	}
	dfs(1);
	DFS(1);
	cout << ans[1].F * dp[1] << " " << ans[1].F << endl;
}