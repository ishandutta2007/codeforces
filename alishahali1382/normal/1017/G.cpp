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
const int mod=1000000007;
const int MAXN=100010, LOG=20;
 
struct Node{
	int sum=0, mx=-1;
};
 
Node Merge(Node x, Node y){
	x.mx=max(x.mx+y.sum, y.mx);
	x.sum+=y.sum;
	return x;
}
 
int n, m, k, u, v, x, y, t, a, b, ans;
int stt[MAXN], fnt[MAXN], ras[MAXN], timer=1;
int sz[MAXN], head[MAXN], h[MAXN], par[MAXN];
Node seg[MAXN<<2];
bool lazy[MAXN<<2];
vector<int> G[MAXN];
 
int dfs1(int node){
	for (int v:G[node]) sz[node]+=dfs1(v);
	return ++sz[node];
}
 
void dfs2(int node, int hd){
	head[node]=hd;
	ras[stt[node]=timer++]=node;
	int big=0;
	for (int v:G[node]) if (sz[v]>sz[big]) big=v;
	if (big) dfs2(big, hd);
	for (int v:G[node]) if (v!=big) dfs2(v, v);
	fnt[node]=timer;
}

void add_lazy(int id, int len){
	lazy[id]=1;
	seg[id].mx=-1;
	seg[id].sum=-len;
}
void shift(int id, int tl, int tr){
	if (!lazy[id]) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl);
	add_lazy(id<<1 | 1, tr-mid);
	lazy[id]=0;
}
void Add(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id].sum+=val;
		seg[id].mx+=val;
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, pos, val);
	Add(id<<1 | 1, mid, tr, pos, val);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);
}

void Set(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tr-tl);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, l, r);
	Set(id<<1 | 1, mid, tr, l, r);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);
}

Node Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return Merge(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}
 
Node GetUp(int v){
	Node res;
	while (v){
		res=Merge(Get(1, 1, n+1, stt[head[v]], stt[v]+1), res);
		v=par[head[v]];
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=2; i<=n; i++) cin>>par[i], G[par[i]].pb(i);
	dfs1(1);
	dfs2(1, 1);
	Set(1, 1, n+1, 1, n+1);
	
	while (m--){
		cin>>t>>v;
		if (t==1){
			Add(1, 1, n+1, stt[v], +1);
			continue ;
		}
		if (t==2){
			Set(1, 1, n+1, stt[v], fnt[v]);
			if (v>1){
				int tmp=GetUp(v).mx;
				Add(1, 1, n+1, stt[v], -tmp-1);
			}
			continue ;
		}
		Node tmp=GetUp(v);
		if (tmp.mx>=0) cout<<"black\n";
		else cout<<"white\n";
	}
	
	return 0;
}