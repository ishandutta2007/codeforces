#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  505;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, k, a[N], b[N], dp[N][N], ta, tb;

void solve(){
    dp[0][0] = 1;
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>a[i]>>b[i], ta += a[i], tb += b[i];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            dp[i][(j+a[i])%k] = dp[i][(j+a[i])%k]|dp[i-1][j];
            for(int x = 1; x < k; x++){
                if(x > a[i]) break;
                dp[i][(j+a[i]-x)%k] = dp[i][(j+a[i]-x)%k]|(dp[i-1][j]&(x+b[i]>=k));
            }
        }
    }
    for(int i = 0; i < k; i++){
        if(dp[n][i]){
            deb1((ta+tb-i)/k);
            break;
        }
    }
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