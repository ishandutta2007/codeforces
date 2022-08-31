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
 
const ll   N     =  505;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,a[N],dp[N][N],dp2[N];

ll solve(ll l,ll r){
    if(l == r) return dp[l][r] = a[r];
    if(dp[l][r] != 0) return dp[l][r];
    for(int i = l; i < r; i++){
        ll ls = solve(l,i);
        ll rs = solve(i+1,r);
        if(ls > 0 && ls == rs) return dp[l][r] = ls+1;
    }
    return dp[l][r] = -1;
}

int main(){
    fastio;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        dp2[i] = i+1;
    }
    //cout<<solve(2,4);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            //cout<<j<<" "<<i<<" "<<solve(j,i)<<endl;
            if(solve(j,i) != -1)
                dp2[i] = min(dp2[i],dp2[j-1]+1);
        }
    }
    cout<<dp2[n-1]<<endl;
}