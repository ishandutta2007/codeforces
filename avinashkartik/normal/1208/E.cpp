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

ll test = 1, n, m, w, a[N], ans[N], pre[N];

ll tree[4*N+8];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = a[start];
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = max(tree[2*node],tree[2*node+1]);
	}
}

ll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return -INF;
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	ll p1 = query(2*node, start, mid, l, r);
	ll p2 = query(2*node+1, mid+1, end, l, r);
	return max(p1,p2);
}

void solve(){
	cin>>m>>w;
	while(m--){
		cin>>n;
		for(int i = 1; i <= n; i++) cin>>a[i];
		a[0] = a[n+1] = 0;
		build(1,0,n+1);
		int st,en;
		for(ll i = 1; i <= w; i++){
			if(i <= w-n) st = 0;
			else st = i-(w-n);
			if(i > n) en = n+1;
			else en = i;
			if(st == 0 and en == n+1){
				ll x = query(1,0,n+1,st,i);
				pre[i] += x;
				pre[w-n+1] -= x;
				i = w-n;
			}
			else ans[i] += query(1,0,n+1,st,i);
		}
	}
	for(int i = 1; i <= w; i++) pre[i] += pre[i-1], cout<<ans[i]+pre[i]<<" ";
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