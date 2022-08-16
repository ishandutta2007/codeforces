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
 
const ll   N     =  1e+5;;
const ll   MAXN  =  1e+9;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,a,b;
vpll sol;

int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        if(a > b) swap(a,b);
        ll i = 1;
        while(a < b){
            a += i;
            i++;
        }
        if((a-b)%2 == 0){
            cout<<i-1<<endl;
        }
        else{
            if(a-i+1 == b-1) cout<<i<<endl;
            else if(i%2 == 1) cout<<i<<endl;
            else cout<<i+1<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}