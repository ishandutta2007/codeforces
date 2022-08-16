#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  5e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], dp[N][N/2][2];

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	a[0] = a[n+1] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= (n+1)/2; j++){
			if(j == 0) dp[i][j][1] = INF;
			else dp[i][j][0] = dp[i][j][1] = INFi;
		}
	}
	dp[0][0][0] = 0;
	dp[1][1][1] = max(0ll,a[2]-a[1]+1) + max(0ll,a[0]-a[1]+1);
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= (n+1)/2; j++){
			ll x = dp[i-2][j-1][0] + max(0ll,a[i+1]-a[i]+1) + max(0ll,a[i-1]-a[i]+1);
			ll y = dp[i-2][j-1][1] + max(0ll,a[i+1]-a[i]+1) + max(0ll,min(a[i-1],a[i-2]-1)-a[i]+1);
			dp[i][j][1] = min(x,y);
			dp[i][j][0] = min(dp[i-1][j][0],dp[i-1][j][1]);
		}
	}
	for(int j = 1; j <= (n+1)/2; j++){
		ll res = INFi;
		for(int i = 1; i <= n; i++){
			res = min(res,dp[i][j][1]);
		}
		cout<<res<<" ";
	}
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