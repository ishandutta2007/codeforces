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
int n, mn, mx;
bool was[N], used[N];
void dfs(int v, int p = -1, bool par = 0){
	bool o = 1;
	for(auto to : g[v]){
		if(to == p)
			continue;
		o = 0;
		dfs(to, v, par ^ 1);
	}
	if(o){
		if(was[p])
			mx--;
		was[p] = 1;
		used[par] = 1;
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	int root;
	for(int i = 1; i <= n; i++)
		if(g[i].size() > 1)
			root = i;
	mx = n - 1;
	dfs(root);
	if(used[0] && used[1])
		mn = 3;
	else
		mn = 1;
	printf("%d %d", mn, mx);
}