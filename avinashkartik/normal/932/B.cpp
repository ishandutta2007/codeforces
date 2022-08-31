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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll t=1,n,ans[N],dp[N][10];

int main(){
    fastio;
    cin>>t;
    for(int i = 0; i < 10; i++) ans[i] = i;
    for(int i = 10; i < N; i++){
        ll res = 1;
        ll j = i;
        while(j){
            if(j%10) res *= (j%10);
            j /= 10;
        }
        ans[i] = ans[res];
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j < 10; j++){
            dp[i][j] = dp[i-1][j]; 
        }
        dp[i][ans[i]] += 1;
    }
    while(t--){
        ll l,r,k;
        cin>>l>>r>>k;
        cout<<dp[r][k] - dp[l-1][k]<<endl;
    }
}