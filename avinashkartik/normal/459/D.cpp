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

int test = 1, n, a[N];
um m,m1,m2;
int tree[4*N+8];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = m1[start];
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node]+tree[2*node+1];
	}
	//deb3(start,end,node)
}

void update(int node, int start, int end, int ind){
	if(start == end){
		tree[node] -= 1;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= ind and ind <= mid)
			update(2*node, start, mid, ind);
		else
			update(2*node+1, mid+1, end, ind);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int node, int start, int end, int l, int r){
	if(r < start or end < l)
		return 0;
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return p1+p2;
}

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = n; i > 0; i--){
		m[a[i]]++;
		m1[m[a[i]]]++;
	}
    build(1,1,n);
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		m2[a[i]]++;
		update(1,1,n,m[a[i]]);
		m[a[i]]--;
		ans += query(1,1,n,1,m2[a[i]]-1);
	}
	deb1(ans)
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