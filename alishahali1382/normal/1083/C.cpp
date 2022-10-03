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
const int MAXN=200010, LOG=18;

int n, m, k, u, v, x, y, t, a, b, ans;
int stt[MAXN], fnt[MAXN], timer=1;
int par[MAXN], ras[MAXN], LG[MAXN];
int SP[LOG][MAXN], h[MAXN];
int P[MAXN], Q[MAXN];
pii seg[MAXN<<2];
vector<int> G[MAXN];

void dfs(int node){
	ras[stt[node]=timer++]=node;
	h[node]=h[par[node]]+1;
	for (int v:G[node]) dfs(v);
	fnt[node]=timer;
}

inline int Lca(int x, int y){
	if (x==y) return x;
	x=stt[x];
	y=stt[y];
	if (x>y) swap(x, y);
	int lg=LG[y-x], u=SP[lg][x], v=SP[lg][y-(1<<lg)];
	return (h[u]<h[v]?u:v);
}

inline int Dist(int u, int v){
	return h[u]+h[v]-2*h[Lca(u, v)];
}

pii Merge(pii i, pii j){
	if (i.first==-1 || j.first==-1) return {-1, -1};
	int A[]={i.first, i.second, j.first, j.second};
	int d=-1, u=A[0], v=A[0];
	for (int i=0; i<4; i++) for (int j=i+1; j<4; j++){
		int tmp=Dist(A[i], A[j]);
		if (tmp>d){
			d=tmp;
			u=A[i];
			v=A[j];
		}
	}
	for (int i=0; i<4; i++) if (d!=Dist(u, A[i])+Dist(v, A[i])) return {-1, -1};
	return {u, v};
}

void Set(int id, int tl, int tr, int pos, int val){
	if (pos<tl || tr<=pos) return ;
	if (tr-tl==1){
		seg[id]={val, val};
		return ;
	}
	int mid=(tl+tr)>>1;
	Set(id<<1, tl, mid, pos, val);
	Set(id<<1 | 1, mid, tr, pos, val);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);
}

int Get(int id, int tl, int tr, pii p){
	if (tr-tl==1) return tl;
	int mid=(tl+tr)>>1;
	pii pp=Merge(seg[id<<1], p);
	if (pp.first==-1) return Get(id<<1, tl, mid, p);
	return Get(id<<1 | 1, mid, tr, pp);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) LG[i]=LG[i>>1]+1;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>P[i], Q[P[i]]=i;
	for (int i=2; i<=n; i++) cin>>par[i], G[par[i]].pb(i);
	dfs(1);
	for (int i=1; i<n; i++) SP[0][i]=par[ras[i+1]];
	for (int j=1; j<LOG; j++) for (int i=1; i+(1<<j)<=n; i++){
		int x=SP[j-1][i], y=SP[j-1][i+(1<<(j-1))];
		if (h[x]>h[y]) swap(x, y);
		SP[j][i]=x;
	}
	
	memset(seg, -1, sizeof(seg));
	for (int i=0; i<n; i++) Set(1, 0, n, i, Q[i]);
	cin>>m;
	while (m--){
		cin>>t;
		if (t==2){
			if (seg[1].first==-1) cout<<Get(1, 0, n, {Q[0], Q[0]})<<'\n';
			else cout<<n<<'\n';
		}
		else{
			cin>>x>>y;
			swap(P[x], P[y]);
			swap(Q[P[x]], Q[P[y]]);
			Set(1, 0, n, P[x], x);
			Set(1, 0, n, P[y], y);
		}
	}
	
	return 0;
}