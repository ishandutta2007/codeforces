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
const ll   LEVEL =  log2(N)+1;

int n, q, a[N];
set <int> s;
set <pair<int,pll>, greater<>> g;

void calc(){
	if(s.size() <= 2){
		deb1(0)
		return;
	}
	auto it = s.begin();
	auto it1 = s.end(); it1--;
	int mid = (*it + *it1) / 2;
	pll p = g.begin()->s;
	deb1(p.f-*it + *it1-p.s)
}

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);
	int prv = -1;
	for(auto it : s){
		if(prv != -1) g.insert({it-prv, {prv, it}});
		prv = it;
	}
	calc();
	for(int i = 1; i <= q; i++){
		int x, y; cin >> x >> y;
		if(x == 0){
			auto it = s.lower_bound(y);
			auto it1 = s.upper_bound(y);
			if(it1 != s.end()){
				g.erase({*it1 - *it, {*it, *it1}});
			}
			if(it != s.begin()){
				it--;
				g.insert({*it1 - *it, {*it, *it1}});
				it1--;
				g.erase({*it1 - *it, {*it, *it1}});
			}
			s.erase(y);
		} else{
			s.insert(y);
			auto it = s.lower_bound(y);
			auto it1 = s.upper_bound(y);
			if(it1 != s.end()){
				g.insert({*it1 - *it, {*it, *it1}});
			}
			if(it != s.begin()){
				it--;
				g.erase({*it1 - *it, {*it, *it1}});
				it1--;
				g.insert({*it1 - *it, {*it, *it1}});
			}
		}
		calc();
	}
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