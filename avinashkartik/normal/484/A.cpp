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

const int  N     =  702;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll test = 1, n, dig1[64], dig2[64];
int dp[64][2][2], wh[64][2][2];

void back_track(int ind, int f1, int f2, ll no){
	if(ind == 64){
		deb1(no)
		return;
	}
	int i = wh[ind][f1][f2];
	no += (1ll << (63-ind))*i;
	back_track(ind+1, f1&(i == dig1[ind]), f2&(i == dig2[ind]), no);
}

int mem(int ind, int f1, int f2){
	if(ind == 64) return 0;
	if(dp[ind][f1][f2] != -1) return dp[ind][f1][f2];
	int lo = 0,hi = 1, ans = 0;
	if(f1 == 1) lo = dig1[ind];
	if(f2 == 1) hi = dig2[ind];
	for(int i = lo; i <= hi; i++){
		int x = mem(ind+1, f1&(i == dig1[ind]), f2&(i == dig2[ind])) + i;
		if(x > ans){
			ans = x;
			wh[ind][f1][f2] = i;
		}
	}
	return dp[ind][f1][f2] = ans;
}

void solve(){
	mset(dig1,0);
	mset(dig2,0);
	mset(dp,-1);
	mset(wh,0);
	ll l, r; cin >> l >> r;
	for(int i = 0; i < 64; i++){
		int x = (((1ll << i) & l) >> i);
		dig1[63-i] = x;
		int y = (((1ll << i) & r) >> i);
		dig2[63-i] = y;
	}
	mem(0,1,1);
	back_track(0,1,1,0ll);
}

int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}