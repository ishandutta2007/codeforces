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

int test = 1, n, a[N], q;

int tree[4*N+8];

void build(int node, int start, int end, int d){
	if(start == end){
		tree[node] = a[start];
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid, d-1);
		build(2*node+1, mid+1, end, d-1);
		if(d&1) tree[node] = tree[2*node]|tree[2*node+1];
		else tree[node] = tree[2*node]^tree[2*node+1];
	}
}

void update(int node, int start, int end, int idx, int val, int d){
	if(start == end){
		a[idx] = val;
		tree[node] = val;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val, d-1);
		else
			update(2*node+1, mid+1, end, idx, val, d-1);
		if(d&1) tree[node] = tree[2*node]|tree[2*node+1];
		else tree[node] = tree[2*node]^tree[2*node+1];
	}
}

/*int query(int node, int start, int end, int l, int r){
	if(r < start or end < l)
		return {0,0};
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	ant p1 = query(2*node, start, mid, l, r);
	ant p2 = query(2*node+1, mid+1, end, l, r);
	ant v;
	if(p1.g == 0) v = p2;
	else if(p2.g == 0) v = p1;
	else{
		v.g = __gcd(p1.g,p2.g);
		v.ct = 0;
		if(v.g == p1.g) v.ct += p1.ct; 
		if(v.g == p2.g) v.ct += p2.ct; 
	}
	return v;
}*/

void solve(){
	cin>>n>>q;
	int m = pow(2,n);
	for(int i = 1; i <= m; i++) cin>>a[i];
	build(1,1,m,n);
	while(q--){
		int i,p;
		cin>>i>>p;
		update(1,1,m,i,p,n);
		deb1(tree[1])
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