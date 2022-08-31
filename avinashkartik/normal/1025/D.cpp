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

int test = 1, n, a[N];
bool dp[N][N][2], ok[N][N];

void solve(){
	mset(dp,true);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(__gcd(a[i],a[j]) > 1) ok[i][j] = true;
		}
	}
	for(int i = 1; i <= n-1; i++) if(!ok[i][i+1]) dp[i][i+1][0] = dp[i][i+1][1] = false;
	for(int j = 2; j < n; j++){
		for(int i = 1; i <= n-j; i++){
			dp[i][i+j][0] = dp[i][i+j][1] = false;
			for(int r = i; r < i+j; r++){
				dp[i][i+j][1] |= (dp[i][r][0] && dp[r+1][i+j][1] && ok[i][r+1]);
				dp[i][i+j][1] |= (dp[i][r][1] && dp[r+1][i+j][1] && ok[r][r+1]);
				dp[i][i+j][0] |= (dp[i][r][0] && dp[r+1][i+j][1] && ok[r][i+j]);
				dp[i][i+j][0] |= (dp[i][r][0] && dp[r+1][i+j][0] && ok[r][r+1]);
			}
		}
	}
	cout << (((dp[1][n][0]|dp[1][n][1]) == 1)? "Yes" : "No") << "\n";
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