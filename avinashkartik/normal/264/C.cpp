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

const int  N     =  1e5+5;
const int  mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, q, c[N], v[N], dp[N];

ll calc(ll a, ll b){
	for(int i = 1; i <= n; i++) dp[i] = -INF;
	ll mx1 = 0, mx2 = 0, c1 = 0, c2 = 0;
	for(int i = 1; i <= n; i++){
		if(c1 == c[i]){
			ll res = max(mx1 + v[i]*a, mx2 + v[i]*b);
			mx1 = max(mx1, res);
			dp[c[i]] = max(dp[c[i]], res);
		} else {
			ll res = max(dp[c[i]] + v[i]*a, mx1 + v[i]*b);
			if(res > mx1){
				mx2 = mx1, c2 = c1;
				mx1 = res, c1 = c[i];
			} else if(res > mx2){
				mx2 = res, c2 = c[i];
			}
			dp[c[i]] = max(dp[c[i]], res);
		}
	}
	return mx1;
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> c[i]; 
    for(int i = 1; i <= q; i++){
    	ll a, b; cin >> a >> b;
    	deb1(calc(a, b))
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