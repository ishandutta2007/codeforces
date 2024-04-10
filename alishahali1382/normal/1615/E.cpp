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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

ll ans=-INF;
int n, m, k, u, v, x, y, t, a, b;
int stt[MAXN], fnt[MAXN], ras[MAXN], timer=1;
int par[MAXN], h[MAXN], dead[MAXN];
pii seg[MAXN<<2];
int lazy[MAXN<<2];
vector<int> G[MAXN];

inline void add_lazy(int id, int val){
	lazy[id]+=val;
	seg[id].first+=val;
}
inline void shift(int id){
	if (lazy[id]){
		add_lazy(id<<1, lazy[id]);
		add_lazy(id<<1 | 1, lazy[id]);
		lazy[id]=0;
	}
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
pii Build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]={h[ras[tl]], ras[tl]};
	int mid=(tl+tr)>>1;
	return seg[id]=max(Build(id<<1, tl, mid), Build(id<<1 | 1, mid, tr));
}
void dfs(int node){
	ras[timer]=node;
	stt[node]=timer++;
	h[node]=h[par[node]]+1;
	for (int v:G[node]) if (v!=par[node]) par[v]=node, dfs(v);
	fnt[node]=timer;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1);
	Build(1, 1, n+1);
	int b=n;
	for (int r=1; r<=k; r++){
		int v=seg[1].second;
		while (v && !dead[v]){
			Add(1, 1, n+1, stt[v], fnt[v], -1);
			Add(1, 1, n+1, stt[v], stt[v]+1, -inf);
			dead[v]=1;
			b--;
			v=par[v];
		}
//		debug2(r, b)
		if (2*b<=n) ans=max(ans, 1ll*(r-b)*(n-r-b));
		else ans=max(ans, 1ll*(r-n/2)*(n-r-n/2));
	}
	cout<<ans<<"\n";
	
	return 0;
}