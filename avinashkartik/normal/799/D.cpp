#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  3e5+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a, b, w, h, m;
ll arr[N], dp1[(1<<17)], dp2[(1<<17)], ans = INF;
vll v, cl;
map <pll, int> vis;

void mem(ll msk,ll val){
	if(dp1[msk] != -1) return;
	dp1[msk] = val;
	if(val >= a) return;
	for(int i = 0; i < m/2; i++){
		if((msk&(1<<i)) == 0)
			mem(msk+(1<<i),v[i]*dp1[msk]);
	}
}

void mem2(ll msk, ll val, ll ogmsk){
	if(dp2[msk] != -1) return;
	cl.pb(msk);
	dp2[msk] = val;
	//deb3(msk,dp2[msk],a);
	if(val >= a){
		ll weight = w, ct = 0;
		for(int i = 0; i < m/2; i++){
			if(weight >= b) break;
			if((ogmsk&(1<<i)) == 0) weight *= v[i], ct++;
		}
		for(int i = 0; i < (m+1)/2; i++){
			if(weight >= b) break;
			if((msk&(1<<i)) == 0) weight *= v[i+m/2], ct++;
		}
		if(weight >= b) ans = min(ans,ct+__builtin_popcount(msk)+__builtin_popcount(ogmsk));
		return;
	}
	for(int i = 0; i < (m+1)/2; i++){
		if((msk&(1<<i)) == 0)
			mem2(msk+(1<<i),v[i+m/2]*dp2[msk],ogmsk);
	}
}

void solve(){
	mset(dp1,-1);
	mset(dp2,-1);
	mem(0,h);
	for(int i = 0; i < (1<<(m/2)); i++){
		if(dp1[i] == -1) continue;
		if(vis.find({__builtin_popcount(i),dp1[i]}) != vis.end()) continue;
		for(auto it : cl) dp2[it] = -1;
		cl.clear();
		//deb2(i,dp1[i])
		mem2(0,dp1[i],i);
		vis[{__builtin_popcount(i),dp1[i]}] = 1;
	}
	if(ans == INF) ans = -1;
}

int main(){
    fastio;
    //cin>>test;
    cin>>a>>b>>h>>w>>n;
    for(int i = 1; i <= n; i++) cin>>arr[i];
    sort(arr+1,arr+n+1,greater<>());
	for(int i = 1; i <= min(n,34ll); i++) v.pb(arr[i]);
	m = v.size();
	solve();
	swap(h,w);
	solve();
	deb1(ans)
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}