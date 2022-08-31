//#pragma optimization_level 3
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

const ll   N  =  3e+5+5;
const ll   M  =  1e+5+3;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,k,day,ct,a[N],pre[N],dp[N];
vll v;

int main(){
    fastio;
    cin>>n>>k;
    for(int i = 0;i < n;i++){cin>>a[i];}
    sort(a,a+n);
    pre[0] = a[0];
    for(int i = 1;i < n;i++){pre[i] = pre[i-1] + a[i];}
    for(int i = 0;i < n;i++){
        if(i < k) dp[i] = pre[i];
        else dp[i] = dp[i-k] + pre[i];
    }
    for(int i = 0;i < n;i++){cout<<dp[i]<<" ";}
    cout<<endl;
}