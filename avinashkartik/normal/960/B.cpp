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

const ll   N  =  1e+3+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,k1,k2,ans,a[N],b[N],d[N];

int main(){
    fastio;
    cin>>n>>k1>>k2;
    for(int i = 0;i < n;i++){cin>>a[i];}
    for(int i = 0;i < n;i++){cin>>b[i];}
    for(int i = 0;i < n;i++){d[i] = abs(a[i]-b[i]);}
    for(int i = 0;i < k1;i++){
        sort(d,d+n);
        if(d[n-1] == 0) d[n-1] = 1;
        else d[n-1] -= 1;
    }
    for(int i = 0;i < k2;i++){
        sort(d,d+n);
        if(d[n-1] == 0) d[n-1] = 1;
        else d[n-1] -= 1;
    }
    for(int i = 0;i < n;i++){ans += d[i]*d[i];}
    cout<<ans<<endl;
}