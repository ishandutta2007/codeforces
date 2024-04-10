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
const int MAXN=100010, LOG=18;

int n, m, k, u, v, x, y, t, a, b, ans, cnt;
int stt[MAXN], fnt[MAXN], timer=1;
int par[MAXN][LOG], ras[MAXN];
int sum[MAXN], A[MAXN], bad[MAXN];
int seg[MAXN<<2], lazy[MAXN<<2];
vector<pii> G[MAXN];

void add_lazy(int id, int val){
	seg[id]+=val;
	lazy[id]+=val;
}
void shift(int id){
	if (!lazy[id]) return ;
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
	if (r<=tl || tr<=l) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return max(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}
int BSL(int id, int tl, int tr){
	if (tr-tl==1) return tl;
	shift(id);
	int mid=(tl+tr)>>1;
	if (seg[id]==seg[id<<1]) return BSL(id<<1, tl, mid);
	return BSL(id<<1 | 1, mid, tr);
}
int BSR(int id, int tl, int tr){
	if (tr-tl==1) return tl;
	shift(id);
	int mid=(tl+tr)>>1;
	if (seg[id]==seg[id<<1 | 1]) return BSR(id<<1 | 1, mid, tr);
	return BSR(id<<1, tl, mid);
}

void dfs1(int node){
	ras[stt[node]=timer++]=node;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (pii p:G[node]) if (p.first!=par[node][0]){
		par[p.first][0]=node;
		dfs1(p.first);
		Add(1, 1, n+1, stt[p.first], fnt[p.first], p.second);
	}
	fnt[node]=timer;
}

int Lca(int x, int y){
	if (stt[x]>stt[y]) swap(x, y);
	if (fnt[y]<=fnt[x]) return x;
	for (int i=LOG-1; ~i; i--) if (fnt[y]>fnt[par[x][i]]) x=par[x][i];
	return par[x][0];
}

void AddPath(int u, int v){
	//debug2(u, v)
	int lca=Lca(u, v);
	sum[u]++;
	sum[v]++;
	sum[lca]--;
	sum[par[lca][0]]--;
}

void dfs2(int node){
	if (bad[node]){
		int mx1=Get(1, 1, n+1, stt[node], fnt[node]);
		int mx2=max(Get(1, 1, n+1, 1, stt[node]), Get(1, 1, n+1, fnt[node], n+1));
		int l=ras[BSL(1, 1, n+1)], r=ras[BSR(1, 1, n+1)];
		int lca=Lca(l, r);
		//debug(node)
		if (mx1==mx2) AddPath(node, node);
		else if (mx1>mx2) AddPath(lca, node);
		else{
			int v=node;
			for (int i=LOG-1; ~i; i--) if (Get(1, 1, n+1, stt[par[v][i]], fnt[par[v][i]])!=mx2) v=par[v][i];
			v=par[v][0];
			AddPath(v, node);
			if (stt[v]<=stt[lca] && fnt[lca]<=fnt[v]){
				sum[lca]++;
				sum[v]--;
				//debug2(lca, v)
			}
		}
	}
	for (pii p:G[node]) if (p.first!=par[node][0]){
		Add(1, 1, n+1, 1, n+1, +p.second);
		Add(1, 1, n+1, stt[p.first], fnt[p.first], -2*p.second);
		dfs2(p.first);
		Add(1, 1, n+1, 1, n+1, -p.second);
		Add(1, 1, n+1, stt[p.first], fnt[p.first], +2*p.second);
	}
}

int dfs3(int node){
	for (pii p:G[node]) if (p.first!=par[node][0]) sum[node]+=dfs3(p.first);
	return sum[node];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(seg, -31, sizeof(seg));
	cin>>n>>m;
	for (int i=0; i<m; i++) cin>>A[i], bad[A[i]]=1;
	for (int i=1; i<n; i++){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	dfs1(1);
	fnt[0]=n+1;
	/*
	debug(Lca(5, 8))
	return 0;
	*/
	for (int i=0; i<m; i++) Add(1, 1, n+1, stt[A[i]], stt[A[i]]+1, -seg[0]);
	dfs2(1);
	dfs3(1);
	for (int i=1; i<=n; i++)if (!bad[i]){
		if (sum[i]>ans) ans=sum[i], cnt=0;
		cnt+=(ans==sum[i]);
	}
	cout<<ans<<' '<<cnt<<'\n';
	
	return 0;
}
/*

10 5
4 8 7 5 1
5 1 1
2 7 1
4 3 1
10 9 1
10 1 1
1 8 1
10 7 1
10 3 1
7 6 1

*/