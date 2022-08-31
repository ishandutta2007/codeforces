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

ll test = 1, n, h, m, k;
map <ll, vll> add, rem;
vll v, trains;

void solve(){
	trains.pb(0);
	set <ll> s;
	cin>>n>>h>>m>>k;
	for(int i = 1; i <= n; i++){
		int hi, mi; cin>>hi>>mi;
		add[(mi+1)%(m/2)].pb(i);
		rem[(k+mi)%(m/2)].pb(i);
		if(mi%(m/2) > m/2-k) s.insert(i);
		v.pb((mi+1)%(m/2));
		v.pb((k+mi)%(m/2));
		trains.pb(mi%(m/2));
	}
	sort(all(v));
	uniq(v);
	ll ans = 0, res = s.size();
	for(auto it : v){
		for(auto i : add[it]) s.insert(i);
		for(auto i : rem[it]) s.erase(i);
		if(s.size() < res){
			ans = it;
			res = s.size();
		}
	}
	deb2(res,ans)
	vll fres;
	for(int i = 1; i <= n; i++){
		ll t = trains[i];
		if(t == ans) continue;
		if(ans-k < 0){
			if(t > (ans-k+(m/2))%(m/2)) fres.pb(i);
		}
		if(t > max(-1ll,ans-k) and t < ans) fres.pb(i);
	}
	debv(fres)
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