#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int stt[MAXN], fnt[MAXN], timer=1;
int par[MAXN][LOG];
int h[MAXN];
int ans[MAXN];
int seg[MAXN<<2];
int lazy[MAXN<<2];
vector<int> G[MAXN];
vector<piii> query[MAXN];

void add_lazy(int id, int val){
	seg[id]+=val;
	lazy[id]+=val;
}

void shift(int id){
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

int Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return max(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}

void dfs(int node){
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	h[node]=h[par[node][0]]+1;
	stt[node]=timer++;
	for (int v:G[node]) if (v!=par[node][0]){
		par[v][0]=node;
		dfs(v);
	}
	fnt[node]=timer;
}

int LCA(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	if (x==y) return x;
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]) x=par[x][i], y=par[y][i];
	return par[x][0];
}

int dist(int x, int y){
	return h[x]+h[y]-2*h[LCA(x, y)];
}

void dfs2(int node){
	for (auto p:query[node]) ans[p.first]=max(ans[p.first], Get(1, 1, n+1, p.second.first, p.second.second));
	for (int v:G[node]) if (v!=par[node][0]){
		Add(1, 1, n+1, stt[1], fnt[1], +1);
		Add(1, 1, n+1, stt[v], fnt[v], -2);
		dfs2(v);
		Add(1, 1, n+1, stt[1], fnt[1], -1);
		Add(1, 1, n+1, stt[v], fnt[v], +2);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	par[1][0]=1;
	dfs(1);
	for (int i=2; i<=n; i++) Add(1, 1, n+1, stt[i], fnt[i], +1);
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		int dis=(dist(u, v)-1)/2;
		if (h[u]<h[v]) swap(u, v);
		int tmp=u;
		for (int j=0; j<LOG; j++) if (dis&(1<<j)) tmp=par[tmp][j];
		query[u].pb({i, {stt[tmp], fnt[tmp]}});
		query[v].pb({i, {stt[1], stt[tmp]}});
		query[v].pb({i, {fnt[tmp], fnt[1]}});
	}
	dfs2(1);
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}
/*
4
1 4
1 2
2 3
1
1 3

*/