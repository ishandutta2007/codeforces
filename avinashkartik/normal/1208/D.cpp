#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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

ll test = 1, n, a[N], ans[N];

struct val{
	ll v,ind;
};

val tree[4*N+8];
ll lazy[4*N+8];

void build(int node, int start, int end){
	if(start == end){
		tree[node].v = a[start];
		tree[node].ind = start;
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node].v = min(tree[2*node].v,tree[2*node+1].v);
		if(tree[2*node].v == tree[2*node+1].v){
			tree[node].ind = max(tree[2*node].ind,tree[2*node+1].ind);
		}
		else if(tree[node].v == tree[2*node].v) tree[node].ind = tree[2*node].ind;
		else tree[node].ind = tree[2*node+1].ind;
	}
}

void update(int node, int start, int end, int l, int r, ll v){
	if(lazy[node] != 0){ 
		tree[node].v += lazy[node];
		if(start != end){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start > end or start > r or end < l) return;
	if(start >= l and end <= r){
		tree[node].v += v;
		if(start != end){
			lazy[node*2] += v;
			lazy[node*2+1] += v;
		}
	}
	else{
		int mid = (start + end) / 2;
		update(2*node, start, mid, l, r, v);
		update(2*node+1, mid+1, end, l, r, v);
		tree[node].v = min(tree[2*node].v,tree[2*node+1].v);
		if(tree[2*node].v == tree[2*node+1].v){
			tree[node].ind = max(tree[2*node].ind,tree[2*node+1].ind);
		}
		else if(tree[node].v == tree[2*node].v) tree[node].ind = tree[2*node].ind;
		else tree[node].ind = tree[2*node+1].ind;
	}
}

val query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return {INF,0};
	if(lazy[node] != 0){ 
		tree[node].v += lazy[node];
		if(start != end){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	val p1 = query(2*node, start, mid, l, r);
	val p2 = query(2*node+1, mid+1, end, l, r);
	val p;
	p.v = min(p1.v,p2.v);
	if(p1.v == p2.v){
		p.ind = max(p1.ind,p2.ind);
	}
	else if(p.v == p1.v) p.ind = p1.ind;
	else p.ind = p2.ind;
	return p;
}

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	build(1,1,n);
	for(int i = 1; i <= n; i++){
		val v = query(1,1,n,1,n);
		ans[v.ind] = i;
		update(1,1,n,v.ind+1,n,-i);
		update(1,1,n,v.ind,v.ind,INF);
	}
	for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
	cout<<endl;
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