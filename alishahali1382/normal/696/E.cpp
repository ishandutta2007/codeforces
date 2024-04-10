#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;
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

int n, m, k, q, u, v, x, y, t, a, b, ans;
int stt[MAXN], fnt[MAXN], ras[MAXN], timer=1;
int sz[MAXN], par[MAXN], head[MAXN], h[MAXN];
pll seg[MAXN<<2];
ll lazy[MAXN<<2];
set<int> st[MAXN];
vector<int> G[MAXN];

int dfs1(int node){
	h[node]=h[par[node]]+1;
	for (int v:G[node]) if (v!=par[node]){
		par[v]=node;
		sz[node]+=dfs1(v);
	}
	return ++sz[node];
}

void dfs2(int node, int hd){
	head[node]=hd;
	stt[node]=timer++;
	ras[stt[node]]=node;
	int big=0;
	for (int v:G[node]) if (v!=par[node] && sz[v]>sz[big]) big=v;
	if (big) dfs2(big, hd);
	for (int v:G[node]) if (v!=par[node] && v!=big) dfs2(v, v);
	fnt[node]=timer;
}

pll Build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]={INF, ras[tl]};
	int mid=(tl+tr)>>1;
	return seg[id]=min(Build(id<<1, tl, mid), Build(id<<1 | 1, mid, tr));
}

void add_lazy(int id, ll val){
	seg[id].first+=val;
	lazy[id]+=val;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, ll val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

pll Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return min(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}

void Set(int id, int tl, int tr, int pos, ll val){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id].first=val;
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos, val);
	Set(id<<1 | 1, mid, tr, pos, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

pll GetPath(int u, int v){
	pll res={INF, -1};
	while (head[u]!=head[v]){
		if (h[head[u]]>h[head[v]]) swap(u, v);
		res=min(res, Get(1, 1, n+1, stt[head[v]], stt[v]+1));
		v=par[head[v]];
	}
	if (h[u]>h[v]) swap(u, v);
	res=min(res, Get(1, 1, n+1, stt[u], stt[v]+1));
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=m; i++) cin>>x, st[x].insert(i);
	
	dfs1(1);
	dfs2(1, 1);
	Build(1, 1, n+1);
	seg[0]={INF, 0};
	
	for (int i=1; i<=n; i++) if (st[i].size()) Set(1, 1, n+1, stt[i], *st[i].begin());
	
	while (q--){
		cin>>t;
		if (t==2){
			cin>>v>>x;
			Add(1, 1, n+1, stt[v], fnt[v], x);
			continue ;
		}
		vector<int> out;
		cin>>u>>v>>k;
		while (k--){
			pll p=GetPath(u, v);
			if (p.first>=INF) break ;
			int v=p.second, id=*st[v].begin();
			out.pb(id);
			st[v].erase(id);
			if (st[v].empty()) Set(1, 1, n+1, stt[v], INF);
			else Add(1, 1, n+1, stt[v], stt[v]+1, *st[v].begin()-id);
		}
		cout<<out.size()<<' ';
		for (int i:out) cout<<i<<" ";
		cout<<'\n';
	}
	
	return 0;
}