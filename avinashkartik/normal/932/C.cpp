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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll t=1,n,a,b,p[N];

int main(){
    fastio;
    //cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;
        ll cta = -1,ctb=0;
        for(int i = 0; i <= n; i += a){
            if((n-i)%b == 0){
                cta = i/a;
                ctb = (n-i)/b;
                break;
            }
        }
        if(cta == -1){
            cout<<-1<<endl;
            exit(0);
        }
        ll ind = 0;
        for(int i = 1; i <= cta; i++){
            p[ind++] = a*i;
            ll st = a*(i-1)+1;
            for(int j = 1; j < a; j++) p[ind++] = st++;
        }
        ll lst = a*cta;
        for(int i = 1; i <= ctb; i++){
            p[ind++] = lst + b*i;
            ll st = b*(i-1)+1+lst;
            for(int j = 1; j < b; j++) p[ind++] = st++;
        }
        for(int i = 0; i < n; i++) cout<<p[i]<<" ";
        cout<<endl;
    }
}