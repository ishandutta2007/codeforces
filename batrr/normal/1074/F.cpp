#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500, LOG = 19;

vector< int > g[N];
int n, q, tin[N], tout[N], timer, up[LOG][N], u[N << 2];
set< pii > st;
pii t[N << 2];
void dfs(int v, int p){
	tin[v] = ++timer;
	up[0][v] = p;
	for(int i = 1; i < LOG; i++)
		up[i][v] = up[i - 1][up[i - 1][v]];
	for(auto to : g[v])
		if(to != p)
			dfs(to, v);
	tout[v] = timer;	
}
bool upper(int v, int u){
	return tin[v] <= tin[u] && tin[u] <= tout[v];
}
void build(int v, int tl, int tr){
	t[v] = {0, tr - tl + 1};
	if(tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}
void upd(int v, int tl, int tr, int l, int r, int k){
	if(r < tl || tr < l || l > r)
		return;
	if(l <= tl && tr <= r){
		u[v] += k;
		t[v].f += k;
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v << 1, tl, tm, l, r, k);
	upd(v << 1 | 1, tm + 1, tr, l, r, k);
	t[v] = {max(t[v << 1].f, t[v << 1 | 1].f) + u[v], 0};
	if(t[v].f == t[v << 1].f + u[v])
		t[v].s += t[v << 1].s;
	if(t[v].f == t[v << 1 | 1].f + u[v])
		t[v].s += t[v << 1 | 1].s;
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1, 1);
	build(1, 1, n);
	while(q--){
		int v, u, k;
		scanf("%d%d", &v ,&u);
		if(v < u)
			swap(v,  u);
		if(st.find({v, u}) != st.end()){
			k = -1;
			st.erase({v, u}); 
		}else{
			k = 1;
			st.insert({v, u}); 
		}
		if(upper(u, v))
			swap(v, u);
		if(upper(v, u)){
			upd(1, 1, n, 1, n, k);
			upd(1, 1, n, tin[u], tout[u], k);
			for(int i = LOG - 1; i >= 0; i--)
				if(!upper(up[i][u], v))
					u = up[i][u];
			upd(1, 1, n, tin[u], tout[u], -k);
		}else{                              
			upd(1, 1, n, tin[u], tout[u], k);
			upd(1, 1, n, tin[v], tout[v], k);
		}
		pii x = t[1];
		if(x.f < st.size())
			x.s = 0;
		printf("%d\n", x.s);
	}
	return 0;
}