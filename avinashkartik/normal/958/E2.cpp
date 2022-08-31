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

const ll   N     =  5e5+5;
const ll   mod   =  1e9;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k, a[N], d[N], ch[N], dp[2][5005][2];

void solve(){
	vpll v;
	cin >> k >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a,a+n);
	for(int i = 0; i < n-1; i++) d[i] = a[i+1] - a[i], v.pb({d[i],i});
	sort(all(v));
	for(int i = 0; i < min(n-1,3*k); i++) ch[v[i].s] = 1;
	int ptr = 0;
	for(int j = 0; j <= k; j++) dp[ptr][j][0] = dp[ptr][j][1] = 1e16;
	dp[ptr][0][0] = 0;
	for(int i = 0; i < n-1; i++){
		if(ch[i] == 0) continue;
		ptr = 1-ptr;
		for(int j = 0; j <= k; j++){
			dp[ptr][j][0] = min(dp[1-ptr][j][1],dp[1-ptr][j][0]);
			if(ch[i-1] == 1) dp[ptr][j+1][1] = dp[1-ptr][j][0]+d[i];
			else dp[ptr][j+1][1] = min(dp[1-ptr][j][0],dp[1-ptr][j][1])+d[i];
		}
	}
	deb1(min(dp[ptr][k][0],dp[ptr][k][1]));
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