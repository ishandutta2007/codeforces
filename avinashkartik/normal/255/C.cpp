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

int n, a[N], dp[N], last[N], ans = 0;

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		dp[a[i]] = last[a[i]] = 1;
		int mx = 0;
		for(int j = i-1; j >= 1; j--){
			if(a[j] == a[i]){
				last[a[i]]++;
				dp[a[i]] = max(dp[a[i]], mx + 1);
				ans = max(ans, dp[a[i]]);
				mx = 0;
			} else {
				if(dp[a[j]] < dp[a[i]] and last[a[j]] != last[a[i]]){
					dp[a[j]] += 2;
					last[a[j]] = last[a[i]];
					mx = max(mx, dp[a[j]]);
				}
				ans = max(ans, dp[a[j]]);
			}
		}
		ans = max(ans, last[a[i]]);
		for(int j = i; j >= 1; j--) dp[a[j]] = last[a[j]] = 0;
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