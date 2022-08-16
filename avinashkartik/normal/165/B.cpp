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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll n,k;
 
ll ch(ll x){
    ll ans = x;
    while(x){
        x /= k;
        ans += x;
    }
    return (ans >= n);
}

void bs(){
    ll l = 1;
    ll r = 1e9;
    while(l <= r){
        ll mid = (l+r)/2;
        if(ch(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout<<(r+1)<<endl;
}
 
int main(){
    fastio;
    cin>>n>>k;
    bs();
}