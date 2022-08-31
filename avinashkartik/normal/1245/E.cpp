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

int a[N][N], adj[N];
ld dp[105][2];

int idx(int i, int j){
	if(i&1) return i*10 + 9-j;
	return i*10 + j;
}

ld mem(int ind, int f){
	if(ind == 99) return 0;
	if(ind >= 93 and ind < 99) return 6;
	if(dp[ind][f] != -1) return dp[ind][f];
	ld ans = 0;
	for(int i = 1; i <= 6; i++){
		ans += mem(ind+i, 0) + 1;
	}
	ans /= 6;
	if(f != 1 and adj[ind]) ans = min(ans, mem(adj[ind], 1));
	return dp[ind][f] = ans;
}

void solve(){
	mset(dp,-1);
	for(int i = 9; i >= 0; i--){
		for(int j = 0; j < 10; j++){
			cin >> a[i][j];
			if(a[i][j]){
				adj[idx(i, j)] = idx(i+a[i][j], j);
			}
		}
	}
	deb1(mem(0,0))
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