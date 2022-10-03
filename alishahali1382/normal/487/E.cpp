#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, q, k, u, v, x, y, t, a, b;
int W[MAXN], W2[MAXN], par[MAXN], h[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
int head[MAXN], sz[MAXN];
int seg[MAXN<<1];
vector<int> G[MAXN], bcc;
vector<pii> E;
multiset<int> st[MAXN];

int dfs1(int node){
	bcc.pb(node);
	int res=h[node]=h[par[node]]+1;
	for (int v:G[node]){
		if (!h[v]) par[v]=node, res=min(res, dfs1(v));
		else res=min(res, h[v]);
	}
	if (res==h[par[node]]){
		while (1){
			int v=bcc.back();
			bcc.pop_back();
			E.pb({node+n, v});
			if (v==node) break ;
		}
		E.pb({node+n, par[node]});
	}
	return res;
}

int dfs2(int node){
	h[node]=h[par[node]]+1;
	for (int v:G[node]) if (v!=par[node]) par[v]=node, sz[node]+=dfs2(v);
	return ++sz[node];
}

void dfs3(int node, int hd){
	stt[node]=timer++;
	head[node]=hd;
	int big=0;
	for (int v:G[node]) if (v!=par[node] && sz[big]<sz[v]) big=v;
	if (big) dfs3(big, hd);
	for (int v:G[node]) if (v!=par[node] && v!=big) dfs3(v, v);
	fnt[node]=timer;
}

void Set(int pos, int val){
	for (seg[pos+=MAXN]=val; pos>1; pos>>=1) seg[pos>>1]=min(seg[pos], seg[pos^1]);
}
int Get(int l, int r){
	int res=seg[0];
	for (l+=MAXN, r+=MAXN; l<r; l>>=1, r>>=1){
		if (l&1) res=min(res, seg[l++]);
		if (r&1) res=min(res, seg[--r]);
	}
	return res;
}

pii GetPath(int x, int y){
	int res=seg[0];
	while (head[x]!=head[y]){
		if (h[head[x]]<h[head[y]]) swap(x, y);
//		debug2(x, y)
		res=min(res, Get(stt[head[x]], stt[x]+1));
		x=par[head[x]];
	}
	if (h[x]<h[y]) swap(x, y);
	res=min(res, Get(stt[y], stt[x]+1));
	return {res, y};
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (int i=1; i<=n; i++) cin>>W[i];
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs1(1);
	for (int i=1; i<=n; i++) G[i].clear();
	for (pii p:E){
//		debugp(p)
		G[p.first].pb(p.second);
		G[p.second].pb(p.first);
	}
	dfs2(1);
	dfs3(1, 1);
	for (int i=1; i<=n; i++) st[par[i]].insert(W[i]);
	memset(seg, 63, sizeof(seg));
	for (int i=n+1; i<=2*n; i++) if (G[i].size()) Set(stt[i], W2[i]=*st[i].begin());
	
	while (q--){
		char typ;
		cin>>typ>>x>>y;
		if (typ=='C'){
			st[par[x]].erase(st[par[x]].find(W[x]));
			W[x]=y;
			st[par[x]].insert(W[x]);
			Set(stt[par[x]], W2[par[x]]=*st[par[x]].begin());
			continue ;
		}
		pii tmp=GetPath(x, y);
		int ans=tmp.first, lca=tmp.second;
//		debug2(ans, lca)
		if (lca>n) ans=min(ans, W[par[lca]]);
		else ans=min(ans, W[lca]);
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
7 9 1
1
2
3
4
5
6
7
1 2
2 5
1 5
2 3
3 4
2 4
5 6
6 7
5 7
A 2 3

*/