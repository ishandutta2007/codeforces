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
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,m,b,t,a[N],vis[N],d,x;

int main(){
    fastio;
    cin>>t;
    while(t--){
        cin>>n;
        d = -1;
        for(int i = 0; i < n; i++){
            cin>>x;
            m = n+1;
            for(int j = 0; j < x; j++){
                cin>>b;
                if(!vis[b]){
                    m = min(m,b);
                }
            }
            if(m != n+1) vis[m] = 1;
            else d = i+1;
        }
        if(d == -1) cout<<"OPTIMAL"<<endl;
        else{
            ll k;
            for(int i = 1; i <= n; i++){
                if(!vis[i]){ k = i; break;}
            }
            cout<<"IMPROVE"<<endl;
            cout<<d<<" "<<k<<endl;
        }
        for(int i = 1; i <= n; i++) vis[i] = 0;
    }
}