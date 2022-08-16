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

int n, a[N], dp[N][2];

int mem(int i, int f){
	if(i > n) return 0;
	if(dp[i][f] != -1) return dp[i][f];
	if(f == 1){
		dp[i][f] = min(mem(i+1, f^1) + a[i], mem(i+2, f^1) + a[i]+a[i+1]);
	} else dp[i][f] = min(mem(i+1, f^1), mem(i+2, f^1));
	return dp[i][f];
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[n+1] = 0;
	for(int i = 1; i <= n+1; i++) dp[i][0] = dp[i][1] = -1;
	deb1(mem(1, 1))
}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}