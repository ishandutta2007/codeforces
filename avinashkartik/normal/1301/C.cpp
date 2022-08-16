#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  unsigned long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<string,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second
#define  endl                  "\n"                
 
const ll   N     =  1e+3+7;
const ll   MAXN  =  1e+9;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll t,n,ct,z,z1,z11,z12,k;

int main(){
    fastio;
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll x = n*(n+1)/2;
        //cout<<x<<endl;
        if(k == 0)
            cout<<(0)<<endl;
        else if(k < n/2){
            z = (n-k)/(k+1);
            z1 = (n-k)%(k+1);
            ct = (z*(z+1)/2)*(k+1-z1) + ((z+2)*(z+1)/2)*(z1);
            cout<<(x-ct)<<endl;
        }
        else
            cout<<(x-n+k)<<endl;
    }
}