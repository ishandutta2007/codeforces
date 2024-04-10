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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int MAXN=300010, SZ=300010*30, LOG=19;
const ll T=3, Z=5364, Mod[]={1000000007, 998244353, 1000000009}, Base[]={10007, 32786, 735168};
typedef array<int, T+1> Hash;

ll tav[MAXN][T];
Hash operator +(Hash x, Hash y){
	for (int i=0; i<T; i++) x[i]=(x[i]*tav[y[T]][i] + y[i])%Mod[i];
	x[T]+=y[T];
	return x;
}
Hash geth(int x){
	Hash res;
	for (int i=0; i<T; i++) res[i]=x+Z;
	res[T]=1;
	return res;
}

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN], B[MAXN], root[MAXN];
int par[LOG][MAXN], h[MAXN];
int L[SZ], R[SZ], ts;
Hash seg[SZ];
vector<int> G[MAXN];

int Build(int tl, int tr){
	int res=++ts;
	if (tr-tl==1){
		seg[res]=geth(0);
		return res;
	}
	int mid=(tl+tr)>>1;
	L[res]=Build(tl, mid);
	R[res]=Build(mid, tr);
	seg[res]=seg[L[res]]+seg[R[res]];
	return res;
}
int Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return id;
	int res=++ts;
	if (tr-tl==1){
		seg[res]=geth(val);
		return res;
	}
	int mid=(tl+tr)>>1;
	L[res]=Set(L[id], tl, mid, pos, val);
	R[res]=Set(R[id], mid, tr, pos, val);
	seg[res]=seg[L[res]]+seg[R[res]];
	return res;
}
int Get(int id, int tl, int tr, int pos){
	if (pos<tl || tr<=pos) return 0;
	if (tr-tl==1) return seg[id][0]-Z;
	int mid=(tl+tr)>>1;
	return Get(L[id], tl, mid, pos)+Get(R[id], mid, tr, pos);
}
int BS(int id1, int id2, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l || seg[id1]==seg[id2]) return -1;
	if (tr-tl==1) return tl;
	int mid=(tl+tr)>>1, res=BS(L[id1], L[id2], tl, mid, l, r);
	if (res==-1) res=BS(R[id1], R[id2], mid, tr, l, r);
	return res;
}
void dfs(int node){
	root[node]=Set(root[par[0][node]], 1, n+1, A[node], B[A[node]]^=1);
	h[node]=h[par[0][node]]+1;
	for (int i=1; i<LOG; i++) par[i][node]=par[i-1][par[i-1][node]];
	for (int v:G[node]) if (v!=par[0][node]) par[0][v]=node, dfs(v);
	B[A[node]]^=1;
}
int Lca(int x, int y){
	if (h[x]<h[y]) swap(x, y);
	for (int i=LOG-1; ~i; i--) if ((h[x]-h[y])&(1<<i)) x=par[i][x];
	if (x==y) return x;
	for (int i=LOG-1; ~i; i--) if (par[i][x]!=par[i][y]) x=par[i][x], y=par[i][y];
	return par[0][x];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int j=0; j<T; j++) tav[0][j]=1;
	for (int i=1; i<MAXN; i++) for (int j=0; j<T; j++) tav[i][j]=tav[i-1][j]*Base[j]%Mod[j];
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	root[0]=Build(1, n+1);
	dfs(1);
	while (m--){
		cin>>u>>v>>l>>r; r++;
		int lca=Lca(u, v), c=A[lca];
		if (l<=c && c<r){
			int cu=Get(root[u], 1, n+1, c);
			int cv=Get(root[v], 1, n+1, c);
			if (cu==cv){
				cout<<c<<"\n";
				continue ;
			}
			int resl=BS(root[u], root[v], 1, n+1, l, c);
			int resr=BS(root[u], root[v], 1, n+1, c+1, r);
			cout<<max(resl, resr)<<"\n";
		}
		else{
			int res=BS(root[u], root[v], 1, n+1, l, r);
			cout<<res<<"\n";
		}
	}
	
	return 0;
}
/*
6 1
3 2 1 3 1 3
1 2
1 3
2 4
2 5
4 6
6 5 1 5


*/