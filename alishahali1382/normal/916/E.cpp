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

int n, m, k, u, v, x, y, t, a, b, root=1;
int A[MAXN];
int st[MAXN], fn[MAXN], timer=1;
int par[MAXN][LOG];
int h[MAXN];
ll seg[MAXN<<2], lazy[MAXN<<2];
vector<int> G[MAXN];

void add_lazy(int id, int len, ll lz){
	seg[id]+=lz*len;
	lazy[id]+=lz;
}

void shift(int id, int tl, int tr){
	if (!lazy[id]) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, lazy[id]);
	add_lazy(id<<1 | 1, tr-mid, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, tr-tl, val);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];
}

ll get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return seg[id];
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid, tr, l, r);
}

void dfs(int node, int p){
	par[node][0]=p;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	h[node]=h[p]+1;
	st[node]=timer++;
	for (int v:G[node]) if (v!=p) dfs(v, node);
	fn[node]=timer;
}

int LCA(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((1<<i)&(h[y]-h[x])) y=par[y][i];
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	if (x!=y) x=par[x][0];
	return x;
}

int badlca(int x, int y){
	int res=LCA(x, y);
	int tmp=LCA(x, root);
	if (h[tmp]>h[res]) res=tmp;
	tmp=LCA(y, root);
	if (h[tmp]>h[res]) res=tmp;
	return res;
}

int go_up(int v){
	int res=root;
	for (int i=LOG-1; i>=0; i--) if (h[par[res][i]]>h[v]) res=par[res][i];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	for (int i=1; i<=n; i++) update(1, 1, n+1, st[i], st[i]+1, A[i]);
	while (m--){
		cin>>t;
		if (t==1){
			cin>>v;
			root=v;
			continue ;
		}
		if (t==2){
			cin>>u>>v>>x;
			v=badlca(u, v);
			//debug2("badlca", v)
			if (v==root){
				update(1, 1, n+1, 1, n+1, x);
				continue ;
			}
			if (st[v]<=st[root] && fn[root]<=fn[v]){
				u=go_up(v);
				update(1, 1, n+1, 1, n+1, x);
				update(1, 1, n+1, st[u], fn[u], -x);			
				continue ;
			}
			update(1, 1, n+1, st[v], fn[v], x);
			continue ;
		}
		cin>>v;
		if (v==root){
			cout<<get(1, 1, n+1, 1, n+1)<<'\n';
			continue ;
		}
		if (st[v]<=st[root] && fn[root]<=fn[v]){
			u=go_up(v);
			cout<<get(1, 1, n+1, 1, n+1)-get(1, 1, n+1, st[u], fn[u])<<'\n';			
			continue ;
		}
		cout<<get(1, 1, n+1, st[v], fn[v])<<'\n';
	}
	
	
	return 0;
}
/*
6 4
1 4 5 11 8 10
1 2
3 1
4 3
4 5
3 6
1 6
2 2 4 -5
1 4
3 3

*/