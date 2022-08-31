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
 
const ll   N     =  5e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, a, b;
set <ll> fa, fb;

void solve(){
	cin>>a>>b;
	ll n = a+b;
	for(ll i = 1; i*i <= a; i++){
		if(a%i == 0){
			fa.insert(i);
			fa.insert(a/i);
		}
	}
	for(ll i = 1; i*i <= b; i++){
		if(b%i == 0){
			fb.insert(i);
			fb.insert(b/i);
		}
	}
	ll ans = INF;
	for(ll i = 1; i*i <= n; i++){
		if(n%i == 0){
			ll x = i, y = n/i;
			auto z = fa.upper_bound(x); z--;
			if(a/(*z) <= y) ans = min(ans,2*(x+y));
			z = fb.upper_bound(x); z--;
			if(b/(*z) <= y) ans = min(ans,2*(x+y));
		}
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