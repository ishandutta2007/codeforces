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

ll test = 1, n, m, dp[N][10];
string s[5];
vll v1(3), v2(3);

int mem(int ind, int msk){
	if(ind == m) return 0;
	if(dp[ind][msk] != -1) return dp[ind][msk];
	int ans = INFi;
	for(int i = 0; i < (1<<n); i++){
		int f = 0, val = 0;
		if(ind){
			for(int j = 0; j < n; j++){
				v1[j] = (msk>>j)&1;
				v2[j] = (i>>j)&1;
			}
			for(int j = 0; j < n-1; j++){
				int x = v1[j]+v1[j+1]+v2[j]+v2[j+1];
				if(x%2 == 0) f = 1;
			}
			if(f == 1) continue;
		}
		for(int j = 0; j < n; j++) val += (((i>>j)&1) != (s[j][ind]-'0'));
		ans = min(ans,mem(ind+1,i)+val);
	}
	return dp[ind][msk] = ans;
}

void solve(){
	cin >> n >> m;
	if(n > 3){
		deb1(-1)
		return;
	}
	if(n == 1){
		deb1(0)
		return;
	}
	for(int i = 0; i < n; i++) cin >> s[i];
	mset(dp,-1);
	deb1(mem(0,0))
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