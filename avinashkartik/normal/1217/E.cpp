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

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, q, a[N], ans[N];

struct NODE{
	ll val[10], ans;
	NODE(){
		for(int i = 0; i < 10; i++) val[i] = INF;
		ans = INF;
	}
};

NODE tree[4*N+8];

NODE newnode(ll x){
	NODE v;
	ll i = 0, n = x;
	while(n){
		int y = n%10;
		if(y) v.val[i] = x;
		i++;
		n /= 10;
	}
	return v;
}

NODE merge(NODE a, NODE b){
	NODE v;
	v.ans = min(a.ans,b.ans);
	for(int i = 0; i < 10; i++){
		if(a.val[i] != INF and b.val[i] != INF) v.ans = min(v.ans,a.val[i]+b.val[i]);
		v.val[i] = min(a.val[i],b.val[i]);
	}
	return v;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = newnode(a[start]);
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = merge(tree[2*node],tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, int val){
	if(start == end){
		tree[node] = newnode(val);
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
		tree[node] = merge(tree[2*node],tree[2*node+1]);
	}
}

NODE query(int node, int start, int end, int l, int r){
	NODE v;
	if(start > end or start > r or end < l)
		return v;
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return merge(p1,p2);
}

void solve(){
	cin>>n>>q;
	for(int i = 1; i <= n; i++) cin>>a[i];
	build(1,1,n);
	while(q--){
		int i, l, r;
		cin>>i>>l>>r;
		if(i == 1) update(1,1,n,l,r);
		else{
			ll ans = query(1,1,n,l,r).ans;
			if(ans == INF) ans = -1;
			deb1(ans)
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