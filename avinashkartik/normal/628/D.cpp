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
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,m,d,dp[2001][2001][2],dig[2001],sz;
string l,r;

ll rec(ll ind, ll s, ll f){
    if(ind == sz){
        return (s==0);
    } 
    if(dp[ind][s][f] != -1) return dp[ind][s][f];
    dp[ind][s][f] = 0;
    ll j = 9;
    if(f == 1) j = dig[ind];
    if(ind%2 == 0){
        for(int i = 0; i <= j; i++){
            if(i == d) continue;
            dp[ind][s][f] += rec(ind+1,(s*10+i)%m,f&(dig[ind]==i));
            dp[ind][s][f] %= mod;
        }
    }
    else{
        if(d <= j) dp[ind][s][f] = rec(ind+1,(s*10+d)%m,f&(dig[ind]==d))%mod;
    }
    return dp[ind][s][f];
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>m>>d>>l>>r;
    sz = r.size();
    for(int i = sz-1; i >= 0; i--){
        dig[i] = r[i]-'0';
    }
    ll rans = rec(0,0,1);
    memset(dp,-1,sizeof(dp));
    ll flag = 0;
    for(int i = sz-1; i >= 0; i--){
        if(flag == 0 && l[i] == 0) dig[i] = 9;
        else if(flag == 0){
            dig[i] = l[i]-'0'-1;
            flag = 1;
        }
        else{
            dig[i] = l[i]-'0';
        }
    }
    ll lans = rec(0,0,1);
    ll ans = rans-lans;
    if(ans < 0) ans += mod;
    cout<<ans<<endl;
}

int main(){
    fastio;
    //cin>>t;
    while(t--){
        solve();
    }
}