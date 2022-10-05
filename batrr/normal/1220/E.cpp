#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector< int > g[N];
int n, m, a[N];
ll dp[N], ans, mx;
bool gg[N], used[N];
    
void dfs(int v, int p){
	used[v] = true;
	dp[v] = a[v];
	for(auto to : g[v]){
		if(to == p)
			continue;
		if(used[to]){
			gg[v] = 1;
		}else{
			dfs(to, v);
			gg[v] |= gg[to];
			dp[v] = max(dp[v], dp[to] + a[v]);
		}
	}
	if(gg[v])
		ans += a[v];
	else
		mx = max(mx, dp[v]);
		
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);         	
	}
	int s;
	scanf("%d", &s);
	dfs(s, s);
	printf("%lld", ans + mx);
	return 0;
}