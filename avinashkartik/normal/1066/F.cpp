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
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, dp[N][2];
map <ll,pll> l,r;
set <ll> s;
vll v;

ll dist(pll x, pll y){
	return abs(x.f-y.f) + abs(x.s-y.s);
}

void solve(){
	cin>>n;
	for(int i = 0; i < n; i++){
		ll x,y;
		cin>>x>>y;
		if(l.find(max(x,y)) == l.end()) l[max(x,y)] = {x,y};
		else if(l[max(x,y)].s > y) l[max(x,y)] = {x,y};
		else if(l[max(x,y)].s == y and l[max(x,y)].f < x) l[max(x,y)] = {x,y};
		if(r.find(max(x,y)) == r.end()) r[max(x,y)] = {x,y};
		else if(r[max(x,y)].f > x) r[max(x,y)] = {x,y};
		else if(r[max(x,y)].f == x and r[max(x,y)].s < y) r[max(x,y)] = {x,y};
		s.insert(max(x,y));
	}
	r[0] = l[0] = {0,0};
	v.pb(0);
	for(auto it : s) v.pb(it);
	for(int i = 1; i < v.size(); i++){
		ll mv = dist(r[v[i]],l[v[i]]);
		dp[i][0] = dp[i-1][0] + dist(r[v[i]],l[v[i-1]]) + mv;
		dp[i][0] = min(dp[i][0], dp[i-1][1] + dist(r[v[i]],r[v[i-1]]) + mv);
		dp[i][1] = dp[i-1][0] + dist(l[v[i]],l[v[i-1]]) + mv;
		dp[i][1] = min(dp[i][1], dp[i-1][1] + dist(l[v[i]],r[v[i-1]]) + mv);
	}
	ll ans = min(dp[v.size()-1][0],dp[v.size()-1][1]);
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