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
 
const ll   N     =  4e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll t=1,n,a[N];
um ct,val;

int main(){
    fastio;
    //cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            a[i] -= i;
            val[a[i]] += i;
            ct[a[i]]++;
        }
        ll maxx = 0;
        for(auto i : val){
            ll res = ct[i.f]*(i.f) + i.s;
            maxx = max(maxx,res);
        }
        cout<<maxx<<endl;
    }
}