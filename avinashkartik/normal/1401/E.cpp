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

ll test = 1, n, m;
pll X[N];
vll L[N], R[N];

ll tree[4*N+8], lazy[4*N+8];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = 0;
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node]+tree[2*node+1];
	}
}

void pushlazy(int start, int end, int node){
	if(lazy[node] == 0) return;
	tree[node] += (end-start+1)*lazy[node];
	if(start != end){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, ll val){
	pushlazy(start,end,node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		lazy[node] += val;
		pushlazy(start,end,node);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, val);
	update(node*2 + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2*node]+tree[2*node+1];
}

ll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return 0;
	pushlazy(start,end,node);
	if(l <= start and end <= r){
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll p1 = query(2*node, start, mid, l, r);
	ll p2 = query(2*node+1, mid+1, end, l, r);
	return p1+p2;
}

void solve(){
	mset(X,0);
	cin >> n >> m;
	ll ans = 1, full = 0;
	for(int i = 1; i <= n; i++){
		int x, l, r; cin >> x >> l >> r;
		if(l == 0 && r == 1e6) full++;
		X[x] = {l,r};
	}
	for(int i = 1; i <= m; i++){
		int y, l, r; cin >> y >> l >> r;
		if(l == 0 && r == 1e6) full++;
		if(l == 0) R[r].pb(y);
		else if(r == 1e6) L[l].pb(y);
	}
	mset(tree,0);
	mset(lazy,0);
	for(int i = 1; i <= 1e6; i++){
		if(X[i].s) update(1,0,1e6,X[i].f,X[i].s,1);
		for(auto it : R[i]){
			ans += query(1,0,1e6,it,it);
		}
	}
	mset(tree,0);
	mset(lazy,0);
	for(int i = 1e6-1; i > 0; i--){
		if(X[i].s) update(1,0,1e6,X[i].f,X[i].s,1);
		for(auto it : L[i]){
			ans += query(1,0,1e6,it,it);
		}
	}
	deb1(ans+full)
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