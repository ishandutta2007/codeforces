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
 
const ll   N     =  3e6+5;
//const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,a,b,mod,x,num[2],rem[2];

ll inv(ll x,ll mod){
    ll y = mod-2;
    ll res = 1;
    while(y > 0){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return res;
}

ll findMinX(){
    ll prod = 1;
    for(int i = 0; i < 2; i++) 
        prod = prod * num[i];
    ll result = 0;
    for(int i = 0; i < 2; i++){
        ll pp = prod / num[i]; 
        result = result + rem[i] * inv(pp, num[i]) * pp;
    }
    return result % prod;
}

void solve(){
    cin>>a>>b>>mod>>x;
    ll p = mod*(mod-1);
    ll q = x/p, r = x%p, res = 1, ans = 0;
    num[0] = mod, num [1] = mod-1;
    for(ll i = 1; i < mod; i++){
        res = (res*a)%mod;
        ll n = (b*inv(res,mod))%mod;
        rem[0] = n, rem[1] = i%(mod-1);
        ll X = findMinX();
        //cout<<i<<" "<<X<<endl;
        ans += q;
        if(X <= r)
            ans += 1;
    }
    cout<<ans<<endl;
}

int main(){
    //fastio;
    //cin>>t;
    while(t--){
        solve();
    }
}