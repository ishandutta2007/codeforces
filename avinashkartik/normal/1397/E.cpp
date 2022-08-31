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

ll n, a[N], dp[N][2], r1, r2, r3, d;

ll mem(int ind, int f){
	if(ind == n){
		if(f == 0) return min(a[ind]*r1+r3, min(r2+r1, (a[ind]+2)*r1) + 2*d);
		else return min({a[ind]*r1+r3-d, r2+r1, (a[ind]+2)*r1});
	}
	if(dp[ind][f] != -1) return dp[ind][f];
	if(f == 1){
		dp[ind][f] = mem(ind+1, 0) + min(a[ind]*r1+min(2*r1, r3), r2+r1);
	} else {
		dp[ind][f] = min(mem(ind+1, 0) + a[ind]*r1+r3, mem(ind+1, 1) + min(r2+r1, (a[ind]+2)*r1) + 2*d);
	}
	return dp[ind][f];
}

void solve(){
	mset(dp, -1);
	cin >> n >> r1 >> r2 >> r3 >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	deb1((n-1)*d + mem(1, 0))
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