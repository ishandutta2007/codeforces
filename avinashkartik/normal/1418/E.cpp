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

ll n, m, a[N], pre[N];

ll fastmod(ll x, ll y = mod - 2){
	ll res = 1;
	while(y){
		if(y&1) res = (res * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return res;
}

ll bs(ll val){
	ll l = 1, r = n, ans = n;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(a[mid] >= val){
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return ans;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++) pre[i] = (pre[i-1] + a[i]) % mod;
    for(int i = 1; i <= m; i++){
    	ll ai, bi; cin >> ai >> bi;
    	int ind = bs(bi);
    	int big = n - ind + 1;
    	int small = ind - 1;
    	if(big < ai) deb1(0)
    	else{
    		ll sm = pre[small] * ((1 - (ai*fastmod(big + 1))%mod + mod) % mod);
    		ll bg = ((pre[n] - pre[small] + mod) % mod) * ((1 - (ai*fastmod(big))%mod + mod)%mod);
    		ll ans = (sm + bg) % mod;
    		deb1(ans)
    	}
    }
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