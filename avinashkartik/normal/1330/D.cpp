#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second                
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  log2(1e9)+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,m,d,suf[N],dp[N][N];
vll p;

ll rec(ll ind, ll l){
    if(l == 1) return suf[ind];
    if(dp[ind][l] != -1) return dp[ind][l];
    dp[ind][l] = 0;
    for(int i = ind; i < n; i++){
        dp[ind][l] += p[i]*rec(i+1,l-1);
        dp[ind][l] %= m;
    }
    return dp[ind][l];
}

void solve(){
    memset(dp,-1,sizeof(dp));
    p.clear();
    memset(suf,0,sizeof(suf));
    cin>>d>>m;
    n = 1;
    while(1){
        if(n*2 > d){
            p.push_back(d-n+1);
            break;
        }
        else p.push_back(n);
        n *= 2;
    }
    n = p.size();
    suf[n-1] = p[n-1];
    for(int i = n-2; i >= 0; i--){
        suf[i] = suf[i+1]+p[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans+rec(0,i))%m;
    }
    cout<<ans<<endl;
}

int main(){
    fastio;
    cin>>t;
    while(t--){
        solve();
    }
}