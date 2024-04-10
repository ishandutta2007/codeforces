#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, LOG = 18;
struct btr{
	int v, u;
	bool ok;
	btr (int _v, int _u){
		v = _v;
		u = _u;
		ok = 1;
	}
	btr(){
		ok = 0;
	}
};
btr t[N << 2], ans;
vector< int > g[N];
int tin[N], tout[N], timer, up[LOG][N], depth[N];
int n, q, p[N], pp[N], mx;
void dfs(int v, int p){
	depth[v] = depth[p] + 1;
	tin[v] = ++timer;
	up[0][v] = p;
	for(int i = 1; i < LOG; i++)
		up[i][v] = up[i - 1][ up[i - 1][v] ];
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
	return depth[v] + depth[u] - 2 * depth[lca(v,u)];
}
bool check(int v, int w, int u){
	return upper(lca(v, u), w) && (upper(w, v) || upper(w, u));
}
btr Merge(btr a, btr b){
	if(!a.ok || !b.ok)
		return btr();
	vector< pii > vec;      
	vec.pb({tin[a.v], a.v});
	vec.pb({tin[a.u], a.u});
	vec.pb({tin[b.v], b.v});
	vec.pb({tin[b.u], b.u});
	pii mx = max(max(vec[0], vec[1]), max(vec[2], vec[3]));
	for(int i = 0; i < 4; i++){
		bool ok = 1;
		for(int q = 0; q < 4; q++)
			if(!check(vec[i].s, vec[q].s, mx.s)){
				ok = 0;
				break;
			}
		if(ok)
			return btr(vec[i].s, mx.s);
	}
	return btr();
}
bool Mergeans(btr a){
	if(!a.ok)
		return 0;
	if(!ans.ok){
		ans = a;
		return 1;
	}
	btr b = Merge(ans, a);
	if(b.ok){
		ans = b;
		return 1;
	}
	return 0;
}
void upd(int v, int tl, int tr, int pos){
	if(tl == tr){
		t[v] = btr(pp[pos], pp[pos]);
		return;
	}
	int tm = (tl + tr) / 2;
	if(pos <= tm)                
		upd(v << 1, tl, tm, pos);
	else
		upd(v << 1 | 1, tm + 1, tr, pos);
	t[v] = Merge(t[v << 1], t[v << 1 | 1]);
}
int get(int v, int tl, int tr){
	if(tl == tr){
		if(Mergeans(t[v]))
			return tr;
		return 0;
	}
	int tm = (tl + tr) / 2;
	if(Mergeans(t[v << 1]))
		return max(tm, get(v << 1 | 1, tm + 1, tr));
	else
		return get(v << 1, tl, tm);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
		p[i]++;
		pp[p[i]] = i;
	}
	for(int i = 2; i <= n; i++){
		int p;
		scanf("%d", &p);
		g[p].pb(i);
	}
	dfs(1, 1);
	for(int i = 1; i <= n; i++)
		upd(1, 1, n, i);
	scanf("%d", &q);
	while(q--){
		int type, v, u;
		scanf("%d", &type);
		if(type == 1){
			scanf("%d%d", &v, &u);
			swap(p[v], p[u]); 
			pp[p[v]] = v;
			pp[p[u]] = u;
			upd(1, 1, n, p[v]);
			upd(1, 1, n, p[u]);
		}else{
			ans = btr();
			printf("%d\n", get(1, 1, n));
		}
	}
	return 0;
}