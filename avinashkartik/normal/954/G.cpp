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

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, r, k, a[N];

bool ch(ll x){
	vll pre(n+1,0);
	ll ct = 0;
	for(int i = 0; i < n; i++){
		if(i) pre[i] += pre[i-1];
		if(a[i]+pre[i] >= x) continue;
		ct += x-(a[i]+pre[i]);
		pre[min(n,i+2*r+1)] -= x-(a[i]+pre[i]);
		pre[i] += x-(a[i]+pre[i]);
		if(ct > k) return 0;
	}
	return 1;
}

void bs(){
	ll l = 0, r = 2e18, ans = 0;
	while(l <= r){
		ll mid = (l+r)/2;
		if(ch(mid)){
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	deb1(ans)
}

void solve(){
	cin >> n >> r >> k;
	vll pre(n+1,0);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		pre[max(0ll,i-r)] += a[i];
		pre[min(n,i+r+1)] -= a[i];
	}
	for(int i = 1; i < n; i++) pre[i] += pre[i-1];
	for(int i = 0; i < n; i++) a[i] = pre[i];
	bs();
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