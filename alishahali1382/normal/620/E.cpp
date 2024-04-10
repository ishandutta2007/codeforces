#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 400010;

struct node{
	ll cnt=0, lazy=0;
	node(ll x=0){
		if (x) cnt=x;
	}
	void operator =(node x){ cnt=x.cnt;}
	node operator +(node x){ return node(cnt|(x.cnt));}
} seg[MAXN<<2];

int n, m, k, u, v, x, y, t, a, b, ans;
int st[MAXN], fn[MAXN], timer;
int col[MAXN];
vector<int> G[MAXN];

void dfs(int node, int par){
	st[node]=++timer;
	for (int v:G[node]) if (v!=par) dfs(v, node);
	fn[node]=timer;
}
/*
void build(int id, int tl, int tr){
	if (tl==tr){
		seg[id].len=1;
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid+1, tr);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}*/

void add_lazy(int id, int color){
	seg[id]=node(1ll<<color);
	seg[id].lazy=color;
}

void shift(int id){
	if (!seg[id].lazy) return ;
	add_lazy(id<<1, seg[id].lazy);
	add_lazy(id<<1 | 1, seg[id].lazy);
	seg[id].lazy=0;
}

void update(int id, int tl, int tr, int l, int r, int color){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, color);
		//debug2(id, color)
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, color);
	update(id<<1 | 1, mid+1, tr, l, r, color);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];
}

node get(int id, int tl, int tr, int l, int r){
	//if (id==1) cerr<<"get "<<l<<' '<<r<<' '<<'\n';
	if (r<tl || tr<l) return node();
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid+1, tr, l, r);
}

int diff(node x){ return __builtin_popcountll(x.cnt);}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>col[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	
	//build(1, 1, n);
	for (int i=1; i<=n; i++) update(1, 1, n, st[i], st[i], col[i]);
	
	while (m--){
		cin>>t>>x;
		if (t==2) cout<<diff(get(1, 1, n, st[x], fn[x]))<<'\n';
		else{
			cin>>y;
			update(1, 1, n, st[x], fn[x], y);
		}
	}
	
	
	return 0;
}
/*
7 3
1 1 1 1 1 1 1
1 2
1 3
1 4
3 5
3 6
3 7
2 1
1 3 2
2 1
*/