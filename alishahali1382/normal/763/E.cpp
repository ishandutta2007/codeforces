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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, q, u, v, x, y, t, l, r, ans;
int par[MAXN], V[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];

int get(int x){
	if (par[x]==x) return x;
	return par[x]=get(par[x]);
}

int join(int x, int y){
	x=get(x);
	y=get(y);
	par[x]=y;
	return x!=y;
}

struct Node{
	int l, r, comp; // [l, r]
	int pref[5];
	int suff[5];
} seg[MAXN<<2];

Node Merge(Node x, Node y){
	if (x.comp==-1) return y;
	if (y.comp==-1) return x;
	Node z;
	z.l=x.l;
	z.r=y.r;
	z.comp=x.comp+y.comp;
	int cnt=0;
	for (int i=0; i<5 && x.l+i<=x.r; i++) par[V[cnt++]=x.l+i]=x.pref[i];
	for (int i=0; i<5 && x.l+5<=x.r-i; i++) par[V[cnt++]=x.r-i]=x.suff[i];
	for (int i=0; i<5 && y.l+i<=y.r; i++) par[V[cnt++]=y.l+i]=y.pref[i];
	for (int i=0; i<5 && y.l+5<=y.r-i; i++) par[V[cnt++]=y.r-i]=y.suff[i];
	
	for (int i=0; i<cnt; i++) mark[V[i]]=1;
	for (int i=0; i<cnt; i++){
		int v=V[i];
		for (int u:G[v]) if (mark[u]) z.comp-=join(u, v);
	}
	for (int i=0; i<cnt; i++) mark[V[i]]=0;
	
	for (int i=0; i<5 && z.l+i<=z.r; i++){
		int u=z.l+i, v=get(u);
		if (z.l+5<=v && v<=z.r-5) par[v]=par[u]=u;
		z.pref[i]=par[u];
	}
	for (int i=0; i<5 && z.l+5<=z.r-i; i++){
		int u=z.r-i, v=get(u);
		if (z.l+5<=v && v<=z.r-5) par[v]=par[u]=u;
		z.suff[i]=par[u];
	}
	return z;
}

void Build(int id, int tl, int tr){
	if (tr-tl==1){
		seg[id].l=seg[id].r=seg[id].pref[0]=tl;
		seg[id].comp=1;
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);
}

Node Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return Merge(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	iota(par, par+MAXN, 0);
	cin>>n>>k>>m;
	while (m--){
		cin>>u>>v;
		if (u>v) swap(u, v);
		G[u].pb(v);
	}
	Build(1, 1, n+1);
	seg[0].comp=-1;
	cin>>q;
	while (q--){
		cin>>l>>r;
		cout<<Get(1, 1, n+1, l, r+1).comp<<'\n';
	}
	
	return 0;
}