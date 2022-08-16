#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  x                     first                 
#define  y                     second                
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  63;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,dp[12][11][2],dig[12],k,sz;

ll rec(ll ind, ll s, ll f1){
    if(ind == sz){
        if(s == 10) return 1;
        return 0;
    }
    if(dp[ind][s][f1] != -1) return dp[ind][s][f1];
    dp[ind][s][f1] = 0;
    ll j = 9;
    if(f1 == 1) j = dig[ind];
    for(int i = 0; i <= j; i++){
        if(s+i > 10) continue;
        dp[ind][s][f1] += rec(ind+1,s+i,f1&(dig[ind]==i));
    }
    return dp[ind][s][f1];
}

ll solve(ll l , ll r){
    memset(dp,-1,sizeof(dp));
    n = r;
    sz = 0;
    while(n){
        sz++;
        n /= 10;
    }
    n = r;
    for(int i = sz-1; i >= 0; i--){
        dig[i] = n%10;
        n /= 10;
    }
    ll rans = rec(0,0,1);
    memset(dp,-1,sizeof(dp));
    n = l-1;
    sz = 0;
    while(n){
        sz++;
        n /= 10;
    }
    n = l-1;
    for(int i = sz-1; i >= 0; i--){
        dig[i] = n%10;
        n /= 10;
    }
    ll lans = rec(0,0,1);
    return rans-lans;
}

ll bs(){
    ll l = 1;
    ll r = 1e11;
    ll ans  = r;
    while(l <= r){
        ll mid = (l+r)/2;
        ll ct = solve(l,mid);
        if(ct >= k){
            ans = mid;
            r = mid - 1;
        }
        else{
            k -= ct;
            l = mid + 1;
        }
    }
    return ans;
}

int main(){
    fastio;
    //cin>>t;
    while(t--){
        cin>>k;
        cout<<bs()<<endl;
    }
}