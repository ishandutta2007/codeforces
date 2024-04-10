#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int MAXN = 200010;

ll n=1, m, k, u, v, x, y, a, b;
ll seg[MAXN<<2], lazy[MAXN<<2];
ll ans[MAXN];
int typ[MAXN], V[MAXN];
int sz[MAXN];
ll W[MAXN];
int par[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
vector<int> G[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll inv(ll x){ return powmod(x, mod-2);}

inline ll _mul(ll a, ll b){
	return a*b%mod;
}

void add_lazy(int id, ll val){
	seg[id]=_mul(seg[id], val);
	lazy[id]=_mul(lazy[id], val);
}

void shift(int id){
	if (lazy[id]==1) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=1;
}

void Mul(int id, int tl, int tr, int l, int r, ll val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Mul(id<<1, tl, mid, l, r, val);
	Mul(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=(seg[id<<1]+seg[id<<1 | 1])%mod;
}

void Set(int id, int tl, int tr, int pos, int val){
	if (tr-tl==1){
		seg[id]=val;
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	if (pos<mid) Set(id<<1, tl, mid, pos, val);
	else Set(id<<1 | 1, mid, tr, pos, val);
	seg[id]=(seg[id<<1]+seg[id<<1 | 1])%mod;
}

ll Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return (Get(id<<1, tl, mid, l, r) + Get(id<<1 | 1, mid, tr, l, r))%mod;
}

void dfs(int node){
	stt[node]=timer++;
	for (int v:G[node]) if (v!=par[node]) dfs(v);
	fnt[node]=timer;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fill(lazy, lazy+MAXN*4, 1);
	cin>>W[1]>>m;
	sz[1]=1;
	for (int i=1; i<=m; i++){
		cin>>typ[i];
		if (typ[i]==2) cin>>V[i];
		else{
			V[i]=++n;
			cin>>par[n]>>W[n];
			G[par[n]].push_back(n);
			sz[n]=1;
			sz[par[n]]++;
		}
	}
	dfs(1);
	for (int i=1; i<=n; i++) Set(1, 1, n+1, stt[i], W[i]);
	for (int i=1; i<=n; i++) Mul(1, 1, n+1, stt[i], fnt[i], sz[i]);
	for (int i=m; i; i--){
		if (typ[i]==1){
			Set(1, 1, n+1, stt[V[i]], 0);
			int tmp=par[V[i]];
			Mul(1, 1, n+1, stt[tmp], fnt[tmp], inv(sz[tmp])*(sz[tmp]-1)%mod);
			sz[tmp]--;
			continue ;
		}
		ll tmp=Get(1, 1, n+1, stt[V[i]], fnt[V[i]]);
		tmp=_mul(tmp, inv(Get(1, 1, n+1, stt[V[i]], stt[V[i]]+1)));
		ans[i]=_mul(tmp, _mul(sz[V[i]], W[V[i]]));
	}
	for (int i=1; i<=m; i++) if (typ[i]==2) cout<<ans[i]<<'\n';
	
	return 0;
}