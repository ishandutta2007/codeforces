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
 
const ll   N     =  1e5+10;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,m,b,t,a[N],vis[N],d,x;

ll fastpow(ll x, ll y){
    ll res = 1;
    while(y){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return res%mod;
}

int main(){
    fastio;
    cin>>n;
    ll ans,ans2;
    for(int i = 1; i < n-1; i++){
        ans = fastpow(10,n-i-1);
        ans = (ans*81)%mod;
        ans = (ans*(n-i-1))%mod;
        ans2 = fastpow(10,n-i);
        ans2 = (ans2*18)%mod;
        cout<<((ans+ans2)%mod)<<" ";
        //cout<<ans<<" "<<ans2<<endl;
    }
    if(n > 1) cout<<"180 10"<<endl;
    else cout<<"10"<<endl;
}