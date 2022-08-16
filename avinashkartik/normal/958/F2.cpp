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
const ll   mod   =  1e9;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, a[N], b[N], ct[N], sum = 0, no = 0;
map <pll, ll> ind;
set <ll> s;

void solve(){
	ll ans = INF;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i], sum += b[i], no += (b[i] == 0);
	for(int i = 1; i <= n; i++){
		ct[a[i]]++;
		ind[{ct[a[i]],a[i]}] = i;
		if(ct[a[i]] >= b[a[i]] and b[a[i]]){
			ll idx = ind[{ct[a[i]]-b[a[i]],a[i]}];
			s.erase(idx-1);
			idx = ind[{ct[a[i]]-b[a[i]]+1,a[i]}];
			s.insert(idx-1);
		}
		if(s.size() != m-no) continue;
		ans = min(ans,i-*s.begin());
	}
	for(int i = 1; i <= m; i++){
		if(ct[i] < b[i]){
			deb1(-1)
			return;
		}
	}
	deb1(ans-sum)
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