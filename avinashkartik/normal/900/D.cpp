#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio                ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back  
#define  mset(a,x)             memset(a,x,sizeof(a))             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ld>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,x,y;
um f;

ll fastmod(ll x, ll y){
    ll res = 1;
    while(y){
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y /= 2;
    }
    return res;
}

ll calc(ll t){
    if(f[t] != 0) return f[t];
    ll g = fastmod(2,t-1);
    g -= 1;
    for(int i = 2; i*i <= t; i++){
        if(t%i == 0){
            g -= calc(t/i);
            if(g < 0) g += mod;
            if(i*i != t){
                g -= calc(i);
                if(g < 0) g += mod;
            }
        }
    }
    f[t] = g;
    return g;
}

void solve(){
    cin>>x>>y;
    f[1] = 1;
    if(y%x != 0)
        cout<<0<<endl;
    else
        cout<<calc(y/x)<<endl;

}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}