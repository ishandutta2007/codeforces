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
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<pll,ll>  um;
typedef  vector<pll>           vpll;
 
const int   N    =  105;
const ll   mod   =  1e9+7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, a[N][N], dp[N][N];

ll calc(ll x){
    ll res;
    if(x <= a[0][0]){
        res = a[0][0]-x;
    }
    else{
        res = (n+m-1)*(x-a[0][0]);
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 and j == 0) continue;;
            ll y = x+i+j;
            if(a[i][j] >= y){
                if(i == 0) dp[i][j] = dp[i][j-1];
                else if(j == 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
                dp[i][j] += a[i][j]-y;
            }
        }
    }
    return res+dp[n-1][m-1];
}

void init(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i][j] = INF;
}

void solve(){
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    ll ans = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            init();
            ans = min(ans,calc(a[i][j]-i-j));
        }
    }
    deb1(ans)
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}