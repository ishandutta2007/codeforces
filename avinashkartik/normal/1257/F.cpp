//#pragma optimization_level 3
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

const ll   MAXN  =  1073741824;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

set <ll> s;
int n,k,u,v1,a[103],b[103];
vpll v;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    fastio;
 
    cin>>n;
    for(int i = 0; i < n;i++)cin>>b[i],s.insert(b[i]);
    ll ct=0;
    for(auto it: s)a[ct++]=it;
    shuffle(a,a+ct,rnd);
    for(ll i = 0; i <= MAXN; i++){
        int flag = 1;
        ll ch = __builtin_popcount(a[0]^i);
        for(ll j = 1; j < ct; j++){
            if(__builtin_popcount(a[j]^i)!=ch){
                flag=0;
                break;
            }
        }
        if(flag){cout<<i;return 0;}
    }
    cout<<-1;
 
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}