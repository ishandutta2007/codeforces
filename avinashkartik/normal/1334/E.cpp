#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, q, f[N], inv[N];
map <ll,map <ll,ll>> ct;

ll calc(ll x){
	ll res = 1, cnt = 0;
	for(auto it : ct[x]){
		cnt += it.s;
		res = (res*inv[it.s])%mod;
	}
	return res*f[cnt]%mod;
}

void getans(ll x, ll y){
	ll g = __gcd(x,y);
	deb1(calc(x/g)*calc(y/g)%mod)
}

void fact(ll n){
	ll m = n;
	for(ll i = 2; i*i <= n; i++){
		int cnt = 0;
		while(n%i == 0) n /= i, cnt++;
		if(cnt) ct[m][i] = cnt;
	}
	if(n > 1) ct[m][n] = 1;
}

ll fastmod(ll x, ll y = mod-2){
	ll res = 1;
	while(y){
		if(y&1) res = (res*x)%mod;
		x = (x*x)%mod;
		y /= 2;
	}
	return res;
}

void solve(){
	cin>>n>>q;
	for(ll i = 1; i*i <= n; i++){
		if(n%i == 0){
			fact(i);
			if(i*i != n) fact(n/i);
		}
	}
	f[0] = 1, inv[0] = 1;
	for(int i = 1; i < 60; i++){
		f[i] = (f[i-1]*i)%mod;
		inv[i] = fastmod(f[i]);
	}
	while(q--){
		ll x, y;
		cin>>x>>y;
		getans(x,y);
	}
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}