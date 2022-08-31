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

ll t=1,n,ans[N];
set <pair<ll,pll>> s;

void solve(){
    cin>>n;
    for(int i = 1; i <= 2*n; i++){
        for(int j = 1; j < i; j++){
            ll x;
            cin>>x;
            s.insert({x,{i,j}});
        }
    }
    ll ct = 0;
    auto it = s.end();
    while(ct != n){
        while(1){
            it--;
            if(ans[(*it).y.x] == 0 && ans[(*it).y.y] == 0){
                ans[(*it).y.x] = (*it).y.y;
                ans[(*it).y.y] = (*it).y.x;
                ct++;
                break;
            }
        }
    }
    for(int i = 1; i <= 2*n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    fastio;
    //cin>>t;
    while(t--){
        solve();
    }
}