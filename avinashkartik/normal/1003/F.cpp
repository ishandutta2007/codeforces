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

const ll   N     =  305;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, dp[N][N], pre[N], mx = 0;
string s[N];

void solve(){
	mset(dp,0);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>s[i], pre[i] = pre[i-1] + s[i].size();
	for(int i = n; i >= 1; i--){
		for(int j = n; j > i; j--){
			if(s[i] != s[j]) continue;
			dp[i][j] = dp[i+1][j+1]+1;
			if(dp[i][j] >= j-i+1) dp[i][j] = j-i;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; i+j <= n; j++){
			int ct = 0;
			for(int k = i+j+1; k <= n; k++){
				if(dp[i][k] > j){
					k += j;
					ct++;
				}
			}
			if(ct)mx = max(mx,(ct+1)*(pre[i+j]-pre[i-1]-1));
		}
	}
	deb1(pre[n]+n-1-mx)
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