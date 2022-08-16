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

const int  N     =  5e5+5;
const int  mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n;

void solve(){
	cin >> n;
	ll m = n;
	vector <int> p, ans, spf[10];
	for(ll i = 2; i*i <= m; i++){
		if(m%i == 0){
			p.pb(i);
			while(m%i == 0) m /= i;
		}
	}
	if(m > 1) p.pb(m);
	if(p.size() == 1){
		while(n%p[0] == 0) ans.pb(n), n /= p[0];
		debv(ans)
		deb1(0)
		return;
	}
	if(p.size() == 2 and p[0]*p[1] == n){
		deb3(p[0], p[1], n)
		deb1(1)
		return;
	}
	set <int> d;
	d.insert(n);
	for(ll i = 2; i*i <= n; i++){
		if(n%i == 0){
			d.insert(i);
			d.insert(n / i);
		}
	}
	for(int i = 0; i < p.size(); i++){
		d.erase(p[i]*p[(i+1)%p.size()]);
	}
	if(p.size() == 2){
		d.erase(n);
		ans.pb(n);
	}
	for(auto it : d){
		for(int i = 0; i < p.size(); i++){
			if(it%p[i] == 0){
				spf[i].pb(it);
				break;
			}
		}
	}
	for(int i = 0; i < p.size(); i++){
		for(auto it : spf[i]) ans.pb(it);
		if(p.size() > 2 or i != p.size() - 1) ans.pb(p[i]*p[(i+1)%p.size()]);
	}
	debv(ans)
	deb1(0)
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}