#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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

const ll   N     =  105;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k, dp[N][N], vis[26], ct = 0;
string s;

void solve(){
    cin>>n>>k>>s;
    s = '.'+s;
    for(int i = n; i > 0; i--){
    	if(vis[s[i]-'a'] == 0) ct++;
    	vis[s[i]-'a'] = 1;
    	dp[1][i] = ct;
    }
    for(int i = 2; i <= n; i++){
    	for(int j = 1; i+j <= n+1; j++){
    		mset(vis,0);
    		for(int k = j; i+k <= n+1; k++){
	    		if(vis[s[k]-'a'] == 0){
	    			vis[s[k]-'a'] = 1;
	    			dp[i][j] += dp[i-1][k+1];
	    		}
	    	}
    	}
    }
    ll ans = 0;
    for(int i = n; i > 0; i--){
    	if(k == 0) break;
		if(k <= dp[i][1]){
			ans += k*(n-i);
			k = 0;
		}
		else{
			ans += dp[i][1]*(n-i);
			k -= dp[i][1];
		}
	    //deb2(ans,k)
    }
    if(k) k -= 1, ans += n;
    if(k) deb1(-1)
    else deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}