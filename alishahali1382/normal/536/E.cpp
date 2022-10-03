#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
typedef pair<pair<int, int>, int> piii;
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 100010;

struct Node{
	int pref=0, suff=0, full=0, sum=0;
};

int n, m, k, u, v, x, y, t, a, b;
int f[MAXN];
int E[MAXN][3];
int stt[MAXN], fnt[MAXN], timer=1;
int sz[MAXN], par[MAXN], head[MAXN], h[MAXN];
int ans[MAXN];
Node seg[MAXN<<2];
vector<int> G[MAXN], vec[MAXN], comp;
vector<piii> Q[MAXN];

Node combine(Node x, Node y){
	Node z;
	z.pref=x.pref+x.full*y.pref;
	z.suff=x.suff*y.full+y.suff;
	z.full=x.full&y.full;
	z.sum=x.sum+y.sum-f[x.suff]-f[y.pref]+f[x.suff+y.pref];
	return z;
}

void Set(int id, int tl, int tr, int pos){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id].pref=seg[id].suff=seg[id].full=1;
		seg[id].sum=f[1];
		return ;
	}
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos);
	Set(id<<1 | 1, mid, tr, pos);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

Node Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return combine(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}

int dfs1(int node){
	h[node]=h[par[node]]+1;
	for (int v:G[node]) if (v!=par[node]){
		par[v]=node;
		sz[node]+=dfs1(v);
	}
	return ++sz[node];
}

void dfs2(int node, int hd){
	stt[node]=timer++;
	head[node]=hd;
	int big=0;
	for (int v:G[node]) if (v!=par[node] && sz[v]>sz[big]) big=v;
	if (big) dfs2(big, hd);
	for (int v:G[node]) if (v!=par[node] && v!=big) dfs2(v, v);
	fnt[node]=timer;
}

int GetPath(int u, int v){
	Node x, y;
	while (head[u]!=head[v]){
		if (h[head[u]]>h[head[v]]) swap(x, y), swap(u, v);
		y=combine(Get(1, 1, n+1, stt[head[v]], stt[v]+1), y);
		v=par[head[v]];
	}
	if (h[u]>h[v]) swap(u, v), swap(x, y);
	y=combine(Get(1, 1, n+1, stt[u]+1, stt[v]+1), y);
	
	swap(x.pref, x.suff);
	return combine(x, y).sum;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<n; i++) cin>>f[i];
	for (int i=1; i<n; i++){
		cin>>E[i][0]>>E[i][1]>>E[i][2];
		G[E[i][0]].pb(E[i][1]);
		G[E[i][1]].pb(E[i][0]);
		comp.pb(E[i][2]);
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	
	for (int i=1; i<n; i++){
		E[i][2]=lower_bound(all(comp), E[i][2])-comp.begin();
		vec[E[i][2]].pb(i);
	}
	for (int i=1; i<=m; i++){
		cin>>u>>v>>x;
		x=lower_bound(all(comp), x)-comp.begin();
		Q[x].pb({{u, v}, i});
	}
	
	dfs1(1);
	dfs2(1, 1);
	seg[0].full=1;
	
	for (int i=n; ~i; i--){
		for (int id:vec[i]){
			int v=E[id][0];
			if (h[E[id][1]]>h[v]) v=E[id][1];
			Set(1, 1, n+1, stt[v]);
		}
		for (piii p:Q[i]){
			int u=p.first.first, v=p.first.second, id=p.second;
			ans[id]=GetPath(u, v);
		}
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}