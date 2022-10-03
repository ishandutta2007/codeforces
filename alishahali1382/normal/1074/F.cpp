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
const int MAXN = 200010, LOG=20;

struct node{
	int mn=0, cnt=0;
	node(int a=0, int b=0) : mn(a), cnt(b){}
} seg[MAXN<<2];

node combine(node x, node y){
	if (x.mn==y.mn) return node(x.mn, x.cnt+y.cnt);
	if (x.mn<y.mn) return x;
	return y;
}

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN][LOG];
int stt[MAXN], fnt[MAXN], timer=1;
int h[MAXN];
int lazy[MAXN<<2];
vector<int> G[MAXN];
vector<pii> child[MAXN];
set<pii> edge;

void dfs(int node, int p){
	stt[node]=timer++;
	h[node]=h[p]+1;
	par[node][0]=p;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (int v:G[node]) if (v!=p){
		dfs(v, node);
		child[node].pb({fnt[v], v});
	}
	fnt[node]=timer;
}

node build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]=node(0, 1);
	int mid=(tl+tr)>>1;
	return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid, tr));
}

void add_lazy(int id, int lz){
	lazy[id]+=lz;
	seg[id].mn+=lz;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (tr<=l || r<=tl) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	build(1, 1, n+1);
	while (m--){
		cin>>u>>v;
		int tmp=1;
		if (stt[u]>stt[v]) swap(u, v);
		if (edge.count({u, v})){
			tmp=-1;
			edge.erase({u, v});
		}
		else edge.insert({u, v});
		if (fnt[v]<=fnt[u]){
			int x=lower_bound(all(child[u]), pii(fnt[v], 0))->second;
			update(1, 1, n+1, stt[x], fnt[x], tmp);
			update(1, 1, n+1, stt[v], fnt[v], -tmp);
		}
		else{
			update(1, 1, n+1, 1, n+1, tmp);
			update(1, 1, n+1, stt[u], fnt[u], -tmp);
			update(1, 1, n+1, stt[v], fnt[v], -tmp);
		}
		cout<<(seg[1].mn==0)*seg[1].cnt<<'\n';
	}
	
	return 0;
}