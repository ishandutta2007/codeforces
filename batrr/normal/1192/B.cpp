#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100500, LOG = 18;

struct tree{
	vector< ll > t, u;
	int n, ind;
	tree(){}
	tree(int _n, int _ind){
		n = _n;
		t.resize(n << 2, 0ll);
		u.resize(n << 2, 0ll);
		ind = _ind;	
	} 
	void upd(int v, int tl, int tr, int l, int r, ll x){
		if(r < tl || tr < l)
			return;
		if(l <= tl && tr <= r){
			t[v] += x;
			u[v] += x;
			return;
		}	
		int tm = (tl + tr) >> 1;
		upd(v << 1, tl, tm, l, r, x);
		upd(v << 1 | 1, tm + 1, tr, l, r, x);
		t[v] = max(t[v << 1], t[v << 1 | 1]) + u[v];
	}
} t[N * LOG];
vector< pii > g[N];
vector< pair< int, pii> > G[N];
set< pair<ll, int> > st[N], ST;

int tin[N], tout[N], timer;

int n, q, k, a[N], b[N], sz[N];
ll m, c[N]; 
bool was[N];

ll getans(int ind){
	auto it = st[ind].begin();
	ll res = it -> f;
	it++;
	return res + it -> f;
}
void UPD(int ind, int l, int r, ll x){        
	ST.erase({getans(t[ind].ind), t[ind].ind});
	st[t[ind].ind].erase({-t[ind].t[1], ind});
	t[ind].upd(1, 1, t[ind].n, l, r, x);
	st[t[ind].ind].insert({-t[ind].t[1], ind});      
	ST.insert({getans(t[ind].ind), t[ind].ind});	
}
void dfs1(int v, int p){
	sz[v] = 1;
	for(auto it : g[v]){
		int to = it.f;
		if(was[to] || to == p)
			continue;
		dfs1(to, v);
		sz[v] += sz[to];
	}
}
int get(int v, int p, int n){
	for(auto it : g[v]){
		int to = it.f;
		if(was[to] || to == p)
			continue;
		if(sz[to] * 2 > n)
			return get(to, v, n);		
	}
	return v;
}
void dfs2(int v, int p, int id){
	tin[v] = ++timer;
	for(auto it : g[v]){
		int to = it.f;
		if(was[to] || to == p)
			continue;
		dfs2(to, v, id);
		int ind = it.s;
		G[ind].pb({id, {tin[to], tout[to]}});
	}
	tout[v] = timer;
}
void build(int v){
	if(v == -1){
		dfs1(1, 1);
		v = get(1, 1, sz[1]);
	}
	was[v] = 1;
	st[v].insert({0, -1});
	st[v].insert({0, -2});
	for(auto it : g[v]){
		int to = it.f; 
		if(was[to])
			continue;
		timer = 0;
		dfs2(to, to, k);
		
		int ind = it.s;
		G[ind].pb({k, {tin[to], tout[to]}});

		t[k++] = tree(tout[to], v); 
	}
	for(auto it : g[v]){
		int to = it.f; 
		if(was[to])
			continue;
		dfs1(to, to);
		int u = get(to, to, sz[to]);
		build(u);
	}
}
int main()
{
	scanf("%d%d%lld", &n, &q, &m);
	for(int i = 0; i < n - 1; i++){
		scanf("%d%d%lld", &a[i], &b[i], &c[i]);
		g[a[i]].pb({b[i], i});	
		g[b[i]].pb({a[i], i});
	}
	build(-1);
	ST.insert({0, -1});
	for(int i = 0; i < n - 1; i++){
		for(auto it : G[i]){
			int ind = it.f;
			int l = it.s.f;
			int r = it.s.s;
			UPD(ind, l, r, c[i]);
		}
	}
	ll ans = 0;
	while(q--){
		int i;
		ll d;
		scanf("%d%lld", &i, &d);
		i = (i + ans) % (n - 1);
		d = (d + ans) % m;
		d = d - c[i];	
		c[i] += d;
		for(auto it : G[i]){
			int ind = it.f;
			int l = it.s.f;
			int r = it.s.s;
			UPD(ind, l, r, d);
		}
		ans = -(ST.begin() -> f);
		printf("%lld\n", ans);
	}

	return 0;
}