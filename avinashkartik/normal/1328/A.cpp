#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
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
 
const ll   N     =  2e5+8;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const ll   INFi  =  0x7f7f7f7f;

ll t,a,b;

int main(){
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a%b == 0) cout<<0<<endl;
        else cout<<b-(a%b)<<endl;
    }
}