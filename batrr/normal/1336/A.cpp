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
int n, k, sz[N], depth[N], dp[N], p[N];
bool used[N];
ll ans;

bool cmp(int i, int j){
	return depth[i] - sz[i] > depth[j] - sz[j];
}  
void f(int v, int p){
	sz[v] = 1; 
	for(auto to : g[v]){
		if(to == p)
			continue;
		depth[to] = depth[v] + 1;
		f(to, v);
		sz[v] += sz[to];
	}
}
void ff(int v, int p){
	for(auto to : g[v]){
		if(to == p)
			continue;
		ff(to, v);
		dp[v] += dp[to];
	}
	if(used[v])
		dp[v]++;
	else
		ans += dp[v];
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	f(1, 1);
	for(int i = 1; i <= n; i++)
		p[i] = i;
	sort(p + 1, p + 1 + n, cmp);
	for(int i = 1; i <= k; i++)
		used[p[i]] = 1;
	ff(1, 1);
	printf("%lld", ans);
}