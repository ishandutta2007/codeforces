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
 
const ll   N     =  2e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,a[N];
set <ll> s;

void sumoflength(){ 
    s.insert(0);
    ll j = 1, ans = 0; 
    for (ll i = 1; i <= n; i++){ 
        while (j <= n && s.find(a[j]) == s.end()){ 
            s.insert(a[j]); 
            j++; 
        }
        //cout<<i<<" "<<j<<endl; 
        ans += (j - i); 
        s.erase(a[i-1]);
    }
    cout<<ans<<endl;
} 

void solve(){
    cin>>n;
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] += a[i-1];
    }
    sumoflength();
}

int main(){
    fastio;
    //cin>>t;
    while(t--){
        solve();
    }
}