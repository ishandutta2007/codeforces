#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;

pll seg[Maxn << 2];
ll lz[Maxn << 2];
void upd(int id, ll x){
	seg[id].F += x;
	lz[id] += x;
}
void shift(int id){
	upd(id << 1, lz[id]);
	upd(id << 1 | 1, lz[id]);
	lz[id] = 0;
}
void add(int id, int l, int r, ll x, int L, int R){
	if((r <= L) || (R <= l)) return ;
	if((l <= L) && (R <= r)){
		upd(id, x);
		return ;
	}
	shift(id);
	int mid = (L + R) >> 1;
	add(id << 1, l, r, x, L, mid);
	add(id << 1 | 1, l, r, x, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]); 
}
void change(int id, int l, int r, pll x, int L, int R){
	if((r <= L) || (R <= l)) return ;
	if((l <= L) && (R <= r)){
		seg[id] = x;
		return ;
	}
	shift(id);
	int mid = (L + R) >> 1;
	change(id << 1, l, r, x, L, mid);
	change(id << 1 | 1, l, r, x, mid, R);
	seg[id] = min(seg[id << 1], seg[id << 1 | 1]); 
}
pll get(int id, int l, int r, int L, int R){
	if((r <= L) || (R <= l)) return {Inf, Inf};
	if((l <= L) && (R <= r)) return seg[id];
	shift(id);
	int mid = (L + R) >> 1;
	return min(get(id << 1, l, r, L, mid), get(id << 1 | 1, l, r, mid, R));
}

vector<ll> G[Maxn], H[Maxn];
ll sub[Maxn], dep[Maxn], par[Log][Maxn];
void DFS(ll u, ll p, ll d){
	sub[u] = 1;
	par[0][u] = p;
	dep[u] = d;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u, d + 1);
		sub[u] += sub[adj];
	}
}
int Lift(int u, int h){
	for(int i = 0; i < Log; i++)
		if(h >> i & 1)
			u = par[i][u];
	return u;
}
int LCA(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	u = Lift(u, dep[u] - dep[v]);
	if(u == v) return u;
	for(int l = Log - 1; l >= 0; l--)
		if(par[l][u] != par[l][v]){
			u = par[l][u];
			v = par[l][v];
		}
	return par[0][u];
}

ll st[Maxn], fn[Maxn], hp[Maxn], T = 1;
void HLD(int u, int p){
	st[u] = T++;
	int mx = -1, big = -1;
	for(auto adj : G[u]){
		if(adj == p) continue;
		if(mx < sub[adj]){
			mx = sub[adj];
			big = adj;
		}
	}
	//cout << "^^ " << u << " " << big << '\n';
	if(big != -1){
		hp[big] = hp[u];
		HLD(big, u);
	}
	for(auto adj : G[u]){
		if(adj == p || adj == big) continue;
		HLD(adj, u);
	}
	fn[u] = T;
}
pll Get(int u, int v){
	//cout << u << " " << v << '\n';
	pll res = {Inf, Inf};
	while(dep[u] >= dep[v]){
		res = min(res, get(1, max(st[v], st[hp[u]]), st[u] + 1, 1, Maxn));
		//res = min(res, get(1, st[u], st[u] + 1, 1, Maxn));
		//if(get(1, st[u], st[u] + 1, 1, Maxn).S == 1) cout << "*** " << u << " " << st[u] << '\n';
		//u = par[0][u];
		
		u = par[0][hp[u]];	
	}
	return res;
}
pll GetPath(int u, int v){
	int lca = LCA(u, v);
	return min(Get(u, lca), Get(v, lca));
}

vector<ll> ans;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	iota(hp, hp + Maxn, 0);
	fill(seg, seg + 4*Maxn, pll(Inf, Inf));
	ll n, m, q;
	cin >> n >> m >> q;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, 0, 1);
	//cerr << "Done DFS\n";
	for(int l = 1; l < Log; l++)
		for(int i = 1; i <= n; i++)
			par[l][i] = par[l - 1][par[l - 1][i]];
	HLD(1, 0);
	//cerr << "Done HLD\n";
	ll c;
	for(int i = 1; i <= m; i++){
		cin >> c;
		H[c].pb(i);
	}
	for(int i = 1; i <= n; i++){
		reverse(all(H[i]));
		if(H[i].size()){
			//cout << "!!!! " << i << '\n';
			change(1, st[i], st[i] + 1, {H[i].back(), i}, 1, Maxn);	
		} else change(1, st[i], st[i] + 1, {Inf, Inf}, 1, Maxn);
	}
	//cerr << "Done Build\n"; cout << "\n";
	ll t, k;
	pll res;
	for(int i = 1; i <= q; i++){
		cin >> t;
		if(t == 1){
			cin >> u >> v >> k;
			ans.clear();
			while(k){
				//cout << "!! " << k << '\n';
				res = GetPath(u, v);
				//cerr << "! " << k << '\n';
				//cout << res.F << " " << res.S << '\n';
				if(res.F > Inf - 10) break;
				if(res.S >= Maxn) break;
				k --;
				//cerr << "! " << k << '\n';
				//cout << "?? " << k << ' ' << res.S << '\n';
				assert(H[res.S].size() > 0);
				ans.pb(H[res.S].back());
				if(H[res.S].size() > 1)
					add(1, st[res.S], st[res.S] + 1, H[res.S][H[res.S].size() - 2] - H[res.S].back(), 1, Maxn);
				else
					change(1, st[res.S], st[res.S] + 1, pll(Inf, Inf), 1, Maxn);
				H[res.S].pop_back();
			}
			cout << ans.size() << ' ';
			for(auto x : ans) cout << x << ' '; cout << '\n';
			//cout << "\n";
		} else {
			cin >> v >> k;
			add(1, st[v], fn[v], k, 1, Maxn);
		}
	}
	
	return 0;
}
/*
5 7 3
3 5
2 3
4 3
1 4
4 1 4 5 4 1 4
2 4 3
1 2 1 2
1 4 2 1

*/