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
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

struct Data{
	int mn, mx;
} seg[MAXN<<2];

int n, m, k, u, v, x, y, t, l, r, ans, out;
int par[MAXN][LOG];
int h[MAXN];
int st[MAXN], fn[MAXN], timer, pos[MAXN];
vector<int> G[MAXN];

Data combine(Data d1, Data d2){
	Data out=d1;
	if (st[d2.mn]<st[out.mn]) out.mn=d2.mn;
	if (st[d2.mx]>st[out.mx]) out.mx=d2.mx;
	return out;
}

void dfs(int node){
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	h[node]=h[par[node][0]]+1;
	pos[timer]=node;
	st[node]=timer++;
	for (int v:G[node]) dfs(v);
	fn[node]=timer;
}

int LCA(int x, int y){
	if (x>n) return y;
	if (y>n) return x;
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	if (x!=y) x=par[x][0];
	return x;
}

Data build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]={tl, tl};
	int mid=(tl+tr)>>1;
	return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid, tr));
}

Data get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return {n+2, n+1};
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return combine(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
}

int rlca(int l, int r){
	Data d=get(1, 1, n+1, l, r);
	return LCA(d.mn, d.mx);
}

int calc(int l, int r, int x){
	return LCA(rlca(l, x), rlca(x+1, r));
}

void solve(){
	cin>>l>>r;
	Data d=get(1, 1, n+1, l, r+1);
	int x=calc(l, r+1, d.mn);
	int y=calc(l, r+1, d.mx);
	if (h[x]>h[y]) cout<<d.mn<<' '<<h[x]-1<<'\n';
	else cout<<d.mx<<' '<<h[y]-1<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=2; i<=n; i++) cin>>par[i][0], G[par[i][0]].pb(i);
	dfs(1);
	build(1, 1, n+1);
	st[n+1]=-1;
	st[n+2]=inf;
	while (m--) solve();
	
	return 0;
}
/*
11 1
1 1 3 3 3 4 2 7 7 6
4 6


*/