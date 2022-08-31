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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, s, a[25];

ll fastmod(ll x, ll y = mod-2){
	ll res = 1;
	while(y){
		if(y&1) res = (res*x)%mod;
		x = (x*x)%mod;
		y /= 2;
	}
	return res;
}

ll ncr(ll n, ll r){
	if(n < r) return 0;
	ll num = 1, den = 1;
	for(int i = 1; i <= r; i++){
		num = num*((n-i+1)%mod)%mod;
		den = (den*i)%mod;
	}
	return num*fastmod(den)%mod;
}

void solve(){
	cin>>n>>s;
	for(int i = 0; i < n; i++) cin>>a[i];
	ll ans = 0;
	for(int msk = 0; msk < (1 << n); msk++){
		ll sum = 0, ct = 0;
		for(int i = 0; i < n; i++){
			if(((1 << i)&msk)) sum += a[i]+1, ct++;
		}
		if(sum <= s){
			if(ct&1) ans -= ncr(n+s-sum-1,n-1)-mod;
			else ans += ncr(n+s-sum-1,n-1);
			ans %= mod;
		}
	}
	deb1(ans);
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