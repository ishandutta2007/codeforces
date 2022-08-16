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

const ll   N     =  1e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll l, r, dp[30][2][2][2][2];

ll mem(int ind, int f1, int f2, int f3, int f4){
	if(ind == -1) return 1;
	if(dp[ind][f1][f2][f3][f4] != -1) return dp[ind][f1][f2][f3][f4];
	ll ans = 0;
	int ub1 = 1, lb1 = 0, ub2 = 1, lb2 = 0;
	if(f1 == 1) ub1 = (r >> ind)&1;
	if(f2 == 1) lb1 = (l >> ind)&1;
	if(f3 == 1) ub2 = (r >> ind)&1;
	if(f4 == 1) lb2 = (l >> ind)&1;
	for(int i = lb1; i <= ub1; i++){
		for(int j = lb2; j <= ub2; j++){
			if(i == 1 and j == 1) continue;
			ans += mem(ind-1, f1&(i == ((r >> ind)&1)), f2&(i == ((l >> ind)&1)), f3&(j == ((r >> ind)&1)), f4&(j == ((l >> ind)&1)));
		}
	}
	return dp[ind][f1][f2][f3][f4] = ans;
}

void solve(){
	mset(dp,-1);
	cin >> l >> r;
	deb1(mem(29,1,1,1,1))
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