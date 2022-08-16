#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  5e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, k, a[N], dp[N];

bool ch(ll diff){
	ll best = n;
	for(int i = 1; i <= n; i++){
		dp[i] = i-1;
		ll range = 0;
		for(int j = i-1; j > 0; j--){
			range += diff;
			if(a[i]-range <= a[j] and a[i]+range >= a[j]) dp[i] = min(dp[i], dp[j]+i-j-1);
		}
		best = min(best, dp[i]+n-i);
	}
	return best <= k;
}

int bs(ll l = 0, ll r = 2e9){
	while(l <= r){
		ll mid = (l+r)/2;
		if(ch(mid)) r = mid - 1;
		else l = mid + 1;
	}
	return r + 1;
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	deb1(bs())
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}