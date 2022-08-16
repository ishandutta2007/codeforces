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

ll test = 1, n;
map <ll,vll> L, R;
map <pll,ll> m, ct;
set <ll> points;

ll calc(){
	ll res = 0, p = 0;
	set <pll> active;
	for(auto it : points){
		for(auto i : R[it]) active.erase({i,it-1});
		if(active.size() == 0 and p) res++;
		for(auto i : L[it]) active.insert({it,i});
		p = active.size();
	}
	return res;
}

void solve(){
	L.clear();
	R.clear();
	points.clear();
	m.clear();
	ct.clear();
	cin>>n;
	for(int i = 0; i < n; i++){
		ll l,r;
		cin>>l>>r;
		L[l].pb(r);
		R[r+1].pb(l);
		points.insert(l);
		points.insert(r+1);
		ct[{l,r}]++;
		m[{l,r}] = 0;
	}
	ll tot = calc();
	ll mx = -INF;
	set <pll> active;
	for(auto it : points){
		for(auto i : R[it]) active.erase({i,it-1});
		if(active.size() == 1) m[*active.begin()]++;
		for(auto i : L[it]) active.insert({it,i});
		if(active.size() == 1) m[*active.begin()]--;
	}
	for(auto it : m) mx = max(mx,it.s*(ct[it.f] == 1));
	deb1(tot+mx)
}

int main(){
	fastio;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}