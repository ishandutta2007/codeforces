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
 
const ll   N     =  4e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll n,dp[maxMask],a[maxMask];
 
int main(){
    fastio;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        cin>>a[i];
        dp[a[i] ^ maxMask - 1] = a[i];
    }
    for(int i = 0; i < maxBits; i++){
        for(int j = 0; j < maxMask; j++){
            if (dp[j] > 0) 
                if((1<<i) == ((1<<i)&j)) dp[j-(1<<i)] = dp[j];
        }
    }
    for(int i = 0; i < n; i++){
        cout<<dp[a[i]]<<" ";
    }
    cout<<endl;
}