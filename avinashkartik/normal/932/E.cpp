#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  f                     first                 
#define  s                     second                
 
const ll   N     =  5003;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll t=1,n,k;
ll dp[N][N];

ll fastmod(ll x, ll y){
    ll res = 1;
    while(y){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return res;
}

int main(){
    fastio;
    cin>>n>>k;
    for(int i = 0; i <= k; i++) dp[0][i] = fastmod(2,n-i);
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = (j*dp[i-1][j] + (n-j)*dp[i-1][j+1])%mod;
        }
    }
    cout<<dp[k][0]<<endl;
}