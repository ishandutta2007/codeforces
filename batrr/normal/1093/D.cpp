#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;


vector< int > comp, g[N];
int n, m;
ll pw[N];
bool was[N], col[N];
void dfs(int v){
	was[v] = 1;
	comp.pb(v);
	for(auto to : g[v])
		if(!was[to]){
			col[to] = col[v] ^ 1;
			dfs(to);
		}
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		g[i].clear();
		was[i] = 0;
		col[i] = 0;
	}
	for(int i = 0; i < m; i++){
		int v, u;
		scanf("%d %d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	int ans = 1;
	bool ok = 1;
	for(int i = 1; i <= n; i++){
		if(was[i])
			continue;
		comp.clear();
		dfs(i);
		int a = 0, b = 0;
		for(auto v : comp){
			for(auto to : g[v])
				if(col[v] == col[to])
					ok = 0;
			if(col[v])
				a++;
			else
				b++;
		}
		ans = 1ll * ans * (pw[a] + pw[b]) % mod;
	}
	if(!ok)
		ans = 0;
	printf("%d\n", ans);
}
int main(){
	pw[0] = 1;
	for(int i = 1; i < N; i++)
		pw[i] = pw[i - 1] * 2 % mod;
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}