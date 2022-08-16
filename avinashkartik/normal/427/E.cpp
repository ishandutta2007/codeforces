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

const int  N     =  1e6+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, m, a[N];

ll f(int mid){
	ll ct = 0, res = 0, last = 1;
	for(int i = 1; i < mid; i++){
		if(a[i] == a[mid]) continue;
		ct++;
		if(ct == m){
			res += 2 * (a[mid] - a[last]);
			ct = 0;
			last = i + 1;
		}
	}
	if(ct) res += 2 * (a[mid] - a[last]);
	ct = 0, last = n;
	for(int i = n; i > mid; i--){
		if(a[i] == a[mid]) continue;
		ct++;
		if(ct == m){
			res += 2 * (a[last] - a[mid]);
			ct = 0;
			last = i - 1;
		}
	}
	if(ct) res += 2 * (a[last] - a[mid]);
	return res;
}

ll ts(){
	int l = 1, r = n;
	while(r - l >= 3){
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;
		if(f(m1) < f(m2)) r = m2;
		else l = m1;
	}
	ll ans = f(l);
	for(int i = l+1; i <= r; i++) ans = min(ans, f(i));
	return ans;
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	deb1(ts())
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