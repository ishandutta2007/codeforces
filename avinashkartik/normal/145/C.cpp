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

ll n, k, ct = 0, f[N], dp[1025][1025];
map <int, int> cnt;

ll fastmod(ll x, ll y = mod-2){
	ll res = 1;
	while(y){
		if(y&1) res = (res*x)%mod;
		x = (x*x)%mod;
		y /= 2;
	}
	return res;
}

ll ncr(int n, int r){
	if(r > n) return 0;
	return f[n] * fastmod(f[r]) % mod *fastmod(f[n-r]) %mod;
}

void solve(){
	cin >> n >> k;
	f[0] = 1;
	for(int i = 1; i <= n; i++) f[i] = (f[i-1]*i)%mod;
	for(int i = 1; i <= n; i++){
		int x, y, f = 0; cin >> x;
		y = x;
		while(y){
			int m = y%10;
			if(m != 4 && m != 7) f = 1;
			y /= 10;
		}
		if(f == 1) ct++;
		else cnt[x]++;
	}
	vector <int> v;
	v.pb(0);
	for(auto it : cnt) v.pb(it.s);
	n = v.size()-1;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++) dp[i][j] = dp[i-1][j];
		for(int j = 1; j <= n; j++){
			dp[i][j] = (dp[i][j] + dp[i-1][j-1]*v[i])%mod;
		}
	}
	ll ans = 0;
	for(int i = 0; i <= k; i++){
		if(i > n) break;
		ans = (ans + dp[n][i] * ncr(ct, k-i))%mod;
	}
	deb1(ans)
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