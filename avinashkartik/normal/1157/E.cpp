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

const ll   N  =  2e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,a[N],b[N],c[N];
set <ll> s;
um m;

int main(){
    fastio;

    cin>>n;
    for(int j = 0; j < n; j++) cin>>a[j];
    for(int j = 0; j < n; j++){
        cin>>b[j];
        s.insert(b[j]);
        m[b[j]]++;
    }
    for(int j = 0; j < n; j++){
        ll lb = n-a[j];
        auto it = s.lower_bound(lb);
        if(it == s.end()){
            it = s.lower_bound(0);
        }
        c[j] = ((*it)+a[j])%n;
        m[(*it)]--;
        if(m[(*it)] == 0) s.erase(*it);
    }
    for(int j = 0; j < n; j++) cout<<c[j]<<" ";
    cout<<endl;

}