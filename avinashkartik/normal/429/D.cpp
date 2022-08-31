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

const int  N     =  4e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n;
vpll points;

ll dist(pll a, pll b){
	return (a.f - b.s) * (a.f - b.s) + (a.s - b.f) * (a.s - b.f);
}

void solve(){
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		sum += x;
		points.pb({i, sum});
	}
	set <pll> s;
	ll best = INFi;
	s.insert({points[0].s, points[0].f});
	for(int i = 1, j = 0; i < n; i++){
		while(j < i and points[i].f - points[j].f > sqrt((ld)best)) s.erase({points[j].s, points[j++].f});
		auto it = s.lower_bound({points[i].s - sqrt((ld)best), -INFi});
		while(it != s.end()){
			if(it->f > points[i].s + sqrt((ld)best)) break;
			best = min(best, dist(*it, points[i]));
			it++;
		}
		s.insert({points[i].s, points[i].f});
	}
	deb1(best)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}