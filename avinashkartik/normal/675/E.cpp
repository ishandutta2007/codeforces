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

ll test = 1, n, q, a[N], dp[N];

pll tree[4*N+8];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = {a[start],start};
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node].f > tree[2*node+1].f? tree[2*node] : tree[2*node+1];
	}
}

pll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return {0,0};
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	pll p1 = query(2*node, start, mid, l, r);
	pll p2 = query(2*node+1, mid+1, end, l, r);
	return p1.f > p2.f? p1 : p2;
}

void solve(){
	cin>>n;
	for(int i = 1; i < n; i++) cin>>a[i]; a[n] = n;
	build(1,1,n);
	dp[n] = 0;
	ll ans = 0;
	for(int i = n-1; i > 0; i--){
		pll p = query(1,1,n,i+1,a[i]);
		dp[i] = dp[p.s]+n-i-a[i]+p.s;
		ans += dp[i];
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