#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 500010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b;
int stt[MAXN], fnt[MAXN], timer=1;
int L[MAXN], R[MAXN];
int par[MAXN];
ll w[MAXN];
ll ans[MAXN];
ll seg[MAXN<<2], lazy[MAXN<<2];
vector<int> G[MAXN];
vector<int> query[MAXN];

void add_lazy(int id, ll lz){
	seg[id]+=lz;
	lazy[id]+=lz;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, ll val){
	//cerr<<"update "<<id<<' '<<tl<<' '<<tr<<' '<<l<<' '<<r<<' '<<val<<'\n';
	if (tr<=l || r<=tl) return ;
	if (l<=tl && tr<=r){
		//cerr<<"add_lazy "<<tl<<' '<<tr<<' '<<val<<endl;
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

ll get(int id, int tl, int tr, int l, int r){
	//cerr<<"get "<<id<<' '<<tl<<' '<<tr<<' '<<l<<' '<<r<<'\n';
	if (r<=tl || tr<=l) return INF;
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return min(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
}

void dfs1(int node){
	stt[node]=timer++;
	for (int v:G[node]) dfs1(v);
	fnt[node]=timer;
}

void dfs2(int node){
	for (int id:query[node]) ans[id]=get(1, 1, n+1, L[id], R[id]+1);
	for (int v:G[node]){
		update(1, 1, n+1, 1, n+1, w[v]);
		update(1, 1, n+1, stt[v], fnt[v], -2*w[v]);
		dfs2(v);
		update(1, 1, n+1, 1, n+1, -w[v]);
		update(1, 1, n+1, stt[v], fnt[v], 2*w[v]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=2; i<=n; i++){
		cin>>par[i]>>w[i];
		G[par[i]].pb(i);
	}
	dfs1(1);
	for (int i=2; i<=n; i++) update(1, 1, n+1, stt[i], fnt[i], w[i]);
	for (int i=1; i<=n; i++) if (G[i].size()) update(1, 1, n+1, stt[i], stt[i]+1, INF);
	for (int i=1; i<=m; i++){
		cin>>v>>L[i]>>R[i];
		query[v].pb(i);
	}
	dfs2(1);
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}
/*
5 1
1 10
1 1
3 2
3 3
4 1 2

*/