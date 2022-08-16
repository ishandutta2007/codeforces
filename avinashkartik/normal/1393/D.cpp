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

const ll   N     =  2e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test = 1, n, m, dp[4][N][N];
string s[N];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i], s[i] = '#'+s[i]+'#';
	s[0] = s[n+1] = string(m+2,'#');
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int x = 0, y = 0;
			if(s[i-1][j] == s[i][j]) x = dp[0][i-1][j];
			if(s[i][j-1] == s[i][j]) y = dp[0][i][j-1];
			dp[0][i][j] = min(x,y)+1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			int x = 0, y = 0;
			if(s[i-1][j] == s[i][j]) x = dp[1][i-1][j];
			if(s[i][j+1] == s[i][j]) y = dp[1][i][j+1];
			dp[1][i][j] = min(x,y)+1;
		}
	}
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			int x = 0, y = 0;
			if(s[i+1][j] == s[i][j]) x = dp[2][i+1][j];
			if(s[i][j-1] == s[i][j]) y = dp[2][i][j-1];
			dp[2][i][j] = min(x,y)+1;
		}
	}
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			int x = 0, y = 0;
			if(s[i+1][j] == s[i][j]) x = dp[3][i+1][j];
			if(s[i][j+1] == s[i][j]) y = dp[3][i][j+1];
			dp[3][i][j] = min(x,y)+1;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ll res = INF;
			for(int k = 0; k < 4; k++) res = min(res,dp[k][i][j]);
			ans += res;
		}
	}
	deb1(ans)
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