#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, LOG = 20, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
vector< int > g[N], G[N];
int tin[N], tout[N], timer, up[LOG][N], depth[N];
int n, q, k, m, nn, a[N], aa[N], b[N], p[N];
bool was[N], used[N];
int dd[N], pr[N];
void dfs(int v, int p){
	up[0][v] = p;
	tin[v] = ++timer;
	for(int i = 1; i < LOG; i++)
		up[i][v] = up[i - 1][ up[i - 1][v] ];
	depth[v] = depth[p] + 1;
	for(auto to : g[v])
		if(to != p)
			dfs(to, v);	
	tout[v] = timer;
}
bool upper(int v, int u){
	return tin[v] <= tin[u] && tin[u] <= tout[v];
}
int lca(int v, int u){
	if(upper(v, u))
		return v;
	if(upper(u, v))
		return u;
	for(int i = LOG - 1; i >= 0; i--)
		if(!upper(up[i][v], u))
			v = up[i][v];
	return up[0][v];
}
int dist(int v, int u){
	return depth[v] + depth[u] - 2 * depth[lca(v, u)];
}
void add(int v){
	if(!was[v])
		p[nn++] = v;
	was[v] = 1;
}
bool cmp(int v, int u){
	return tin[v] < tin[u];
}
void solve(){
	scanf("%d%d", &k, &m);
	add(1);
	for(int i = 0; i < k; i++){
		scanf("%d", &a[i]);
		scanf("%d", &aa[i]);
		add(a[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
		add(b[i]);
	}
	sort(p, p + nn, cmp);
	for(int i = nn - 2; i >= 0; i--)
		add(lca(p[i], p[i + 1]));
	sort(p, p + nn, cmp);
	{
	stack< int > st;
	for(int i = 0; i < nn; i++){
		if(st.empty()){
			st.push(i);
			continue;
		}
		while(!upper(p[st.top()], p[i]))
			st.pop();     
		G[p[st.top()]].pb(p[i]);
		G[p[i]].pb(p[st.top()]);
		st.push(i);
	} 
	}
	for(int i = 0; i < nn; i++)
		dd[p[i]] = inf;

	set< pii > st;
	for(int i = 0; i < k; i++){
		used[a[i]] = 1;
		dd[a[i]] = i;
		pr[a[i]] = i;
		st.insert({dd[a[i]], a[i]});
	}
	while(!st.empty()){
		int v = st.begin() -> s;
		used[v] = 1;
		st.erase(st.begin());
		for(auto to : G[v]){
			if(used[to])
				continue;
			if(dd[to] > pr[v] + (dist(to, a[pr[v]]) + aa[pr[v]] - 1) / aa[pr[v]] * k){
				st.erase({dd[to], to});
				dd[to] = pr[v] + (dist(to, a[pr[v]]) + aa[pr[v]] - 1) / aa[pr[v]] * k;
				pr[to] = pr[v];
				st.insert({dd[to], to}); 			
			}
		}
	}
	for(int i = 0; i < m; i++)
		printf("%d ", dd[b[i]] % k + 1);
	printf("\n");
	
	for(int i = 0; i < nn; i++){
		G[p[i]].clear();
		was[p[i]] = 0;	
		used[p[i]] = 0;
	}
	nn = 0;
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
	dfs(1, 1);
	scanf("%d", &q);
	while(q--)
		solve();
}