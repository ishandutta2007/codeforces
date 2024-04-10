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

vector< pii > g[N];
int n, m, ans;
bool was[N], used[N];
void dfs(int v){
	was[v] = 1;
	for(auto to : g[v]){
		if(used[to.s])
			continue;
		used[to.s] = 1;
		
		if(was[to.f])
			ans++;
		else	
			dfs(to.f);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){	
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb({u, i});
		g[u].pb({v, i});
	}
	for(int i = 1; i <= n; i++)
		if(!was[i])
			dfs(i);
	printf("%d", ans);
	return 0;
}