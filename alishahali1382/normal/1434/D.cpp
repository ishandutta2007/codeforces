#include <bits/stdc++.h>
//#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
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
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1000010, LOG=20;

struct Node{
	ll a0, ab0, ba0;
	ll a1, ab1, ba1;
	ll b, ans;
	Node(){
		a0=-inf, ab0=-inf, ba0=-inf;
		a1=-inf, ab1=-inf, ba1=-inf;
		b=-inf, ans=0;
	}
};

int n, m, k, u, v, x, y, t, ans;
int stt[MAXN], fnt[MAXN], ras[MAXN], timer=1;
int par[MAXN], h[MAXN], H[MAXN], col[MAXN], typ[MAXN];
int E[MAXN][2];
Node seg[MAXN<<2];
int lazy[MAXN<<2];
vector<pii> G[MAXN];

Node Merge(Node &x, Node &y){
	Node z;
	z.b=max(x.b, y.b);
	z.ans=max(x.ans, y.ans);
	
	z.a0=max(x.a0, y.a0);
	z.ab0=max({x.ab0, y.ab0, x.a0+y.b});
	z.ba0=max({x.ba0, y.ba0, x.b+y.a0});
	z.ans=max({z.ans, x.a0+y.ba0, x.ab0+y.a0});
	
	z.a1=max(x.a1, y.a1);
	z.ab1=max({x.ab1, y.ab1, x.a1+y.b});
	z.ba1=max({x.ba1, y.ba1, x.b+y.a1});
	z.ans=max({z.ans, x.a1+y.ba1, x.ab1+y.a1});
	return z;
}

void dfs(int node, int xx){
	stt[node]=timer++;
	h[node]=h[par[node]]+1;
	ras[stt[node]]=node;
	col[node]=xx;
	for (pii p:G[node]) if (p.first!=par[node]){
		par[p.first]=node;
		dfs(p.first, xx^p.second);
		ras[timer++]=node;
	}
	fnt[node]=timer;
}
inline void add_lazy(int id){
	swap(seg[id].a0, seg[id].a1);
	swap(seg[id].ab0, seg[id].ab1);
	swap(seg[id].ba0, seg[id].ba1);
	lazy[id]^=1;
}
void Build(int id, int tl, int tr){
	if (tr-tl==1){
		seg[id].a0=H[tl];
		seg[id].b=-2*H[tl];
		seg[id].ab0=seg[id].ba0=-H[tl];
		if (typ[tl]) add_lazy(id);
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);
}
inline void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1);
	add_lazy(id<<1 | 1);
	lazy[id]=0;
}
void Update(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Update(id<<1, tl, mid, l, r);
	Update(id<<1 | 1, mid, tr, l, r);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v>>x;
		E[i][0]=u;
		E[i][1]=v;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	dfs(1, 0);
	for (int i=1; i<timer; i++){
		typ[i]=col[ras[i]];
		H[i]=h[ras[i]];
	}
	for (int i=1; i<n; i++) if (h[E[i][0]]>h[E[i][1]]) swap(E[i][0], E[i][1]);
	Build(1, stt[1], fnt[1]);
	cin>>m;
	while (m--){
		cin>>v;
		v=E[v][1];
		Update(1, stt[1], fnt[1], stt[v], fnt[v]);
		cout<<seg[1].ans<<"\n";
	}
	
	return 0;
}