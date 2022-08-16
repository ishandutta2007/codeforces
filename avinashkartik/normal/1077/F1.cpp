#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
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
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, k, x, a[N], dp[N][N];

void solve(){
    mset(dp,-1);
    cin>>n>>k>>x;
    for(int i = 1; i <= n; i++) cin>>a[i];
    dp[0][0] = 0;
    for(int i = 1; i <= x; i++){
        set <pll, greater<pll>> s;
        s.insert({dp[i-1][i-1],i-1});
        for(int j = i; j <= n; j++){
            if(j >= i+k) s.erase({dp[i-1][j-k-1],j-k-1});
            pll p = *s.begin();
            if(p.f == -1) break;
            dp[i][j] = p.f+a[j];
            s.insert({dp[i-1][j],j});
        }
    }
    ll ans = -1;
    for(int i = n; i > n-k; i--){
        ans = max(ans,dp[x][i]);
    }
    deb1(ans)
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