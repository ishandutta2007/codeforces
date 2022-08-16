#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m = 60, q, a[N], c[N], in[N], out[N], ind[N], no = 1, t = 0;
vll adj[N];
set <pll> s;

ll tree[4*N+8], lazy[4*N+8];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = (1ll<<c[start]);
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node]|tree[2*node+1];
	}
}

void pushlazy(int start, int end, int node, int val){
	if(val == 0) return;
	tree[node] = (1ll<<val);
	if(start != end){
		lazy[node*2] = val;
		lazy[node*2+1] = val;
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, ll val){
	pushlazy(start,end,node,lazy[node]);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		pushlazy(start,end,node,val);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, val);
	update(node*2 + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2*node]|tree[2*node+1];
}

ll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return 0;
	pushlazy(start,end,node,lazy[node]);
	if(l <= start and end <= r){
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll p1 = query(2*node, start, mid, l, r);
	ll p2 = query(2*node+1, mid+1, end, l, r);
	return p1|p2;
}

void dfs(int x, int p){
	in[x] = t++;
	s.insert({in[x],x});
	c[no] = a[x];
	ind[x] = no++;
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it,x);
	}
	out[x] = t++;
}

void solve(){
	cin>>n>>q;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i < n; i++){
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	build(1,1,n);
	while(q--){
		int x, y, z;
		cin>>z;
		if(z == 1){
			cin>>x>>y;
			auto it = s.lower_bound({out[x],0}); it--;
			int l = ind[x], r = ind[(*it).s];
			update(1,1,n,l,r,y);
		}
		else{
			cin>>x;
			auto it = s.lower_bound({out[x],0}); it--;
			int l = ind[x], r = ind[(*it).s];
			ll v = query(1,1,n,l,r), ct = 0;
			for(int i = 1; i <= m; i++) if((1ll<<i)&v) ct++;
			deb1(ct);
		}
	}
}

int main(){
	fastio;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}