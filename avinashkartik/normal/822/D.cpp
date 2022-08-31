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
 
const ll   N     =  5e+6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll p[N],ch[N],t,l,r;

ll solve(ll x)
{
    ll res = 0;
    while(x > 1) {
        res += (x * (p[x] - 1)) / 2;
        x /= p[x];
    }
    return res;
}

ll mul(ll a,ll b){
    return (ll)((a%mod)*(b%mod))%mod;
}

ll add(ll a,ll b){
    return (ll)((a%mod)+(b%mod))%mod;
}
 
int main(){
    fastio;

    for(ll x = 2; x < N; x++){
        if (p[x] != 0) continue;
        for (int y = x; y < N; y += x)
            if (p[y] == 0)
                p[y] = x;
    }
    
    for(ll x = 2; x < N; x++){
        if(p[x] == x) ch[x] = x*(x-1)/2;
        else{
            ch[x] = mul((x/p[x]),ch[p[x]]);
            ch[x] = add(ch[x],ch[x/p[x]]);
        }
    }

    cin>>t>>l>>r;

    ll ans = 0;

    for(ll i = r; i >= l; i--){
        ans = add(mul(t,ans),ch[i]);
    }

    cout<<ans<<endl;

}