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
 
const ll   N     =  1e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, a[N][N], rct[1000005], cct[1000005], k, p;
multiset <ll, greater<>> r, c;

void solve(){
	cin>>n>>m>>k>>p;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin>>a[i][j];
	for(int i = 0; i < n; i++){
		ll ct = 0;
		for(int j = 0; j < m; j++) ct += a[i][j];
		r.insert(ct);
	}
	for(int i = 0; i < m; i++){
		ll ct = 0;
		for(int j = 0; j < n; j++) ct += a[j][i];
		c.insert(ct);
	}
	ll ans = 0;
	for(int i = 1; i <= k; i++){
		ans += *r.begin();
		rct[i] = ans;
		r.insert(*r.begin()-m*p);
		r.erase(r.begin());
	}
	ans = 0;
	for(int i = 1; i <= k; i++){
		ans += *c.begin();
		cct[i] = ans;
		c.insert(*c.begin()-n*p);
		c.erase(c.begin());
	}
	for(int i = 1; i <= k; i++){
		ans = max(ans,rct[i]+cct[k-i]-(k-i)*i*p);
	}
	deb1(ans)
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