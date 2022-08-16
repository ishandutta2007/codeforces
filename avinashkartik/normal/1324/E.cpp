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
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  2005;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll n,h,l,r,dp[N][N],a[N];
 
ll solve(ll ind, ll ho){
    if(ind == n+1) return 0;
    if(dp[ind][ho] != -1) return dp[ind][ho];
    int f = 0;
    //cout<<ind<<" "<<ho<<endl;
    if(l <= ho && ho <= r && ind != 0) f = 1;
    ll h1 = (ho+a[ind])%h;
    ll h2 = (ho+a[ind]-1)%h;
    dp[ind][ho] = f+max(solve(ind+1,h1),solve(ind+1,h2));
    return dp[ind][ho];
}

int main(){
    fastio;
    memset(dp,-1,sizeof(dp));
    cin>>n>>h>>l>>r;
    for(int i = 0; i < n; i++) cin>>a[i];
    cout<<solve(0,0)<<endl;
}