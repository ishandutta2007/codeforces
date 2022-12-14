#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 3e5 + 5;
const int inf = 1e9;

vector <pii> t[maxn];
ll dp[maxn], pd[maxn], w[maxn];

void dfs(int v, int par = -1){
	vector <ll> g;

	pd[v] = w[v];
	for (auto u : t[v]){
		if (u.F != par){
			dfs(u.F, v);
			g.PB(pd[u.F] - u.S);
			dp[v] = max(dp[v], dp[u.F]);
			pd[v] = max(pd[v], pd[u.F] - u.S + w[v]);
		}
	}
	dp[v] = max(dp[v], pd[v]);
	sort(g.begin(), g.end(), greater <ll>());
	if (g.size() > 1)
		dp[v] = max(dp[v], g[0] + g[1] + w[v]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= n - 1; i++){
		int v, u, c;
		cin >> v >> u >> c;
		t[v].PB({u, c});
		t[u].PB({v, c});
	}
	dfs(1);
	cout << dp[1] << endl;
}