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
 
const ll   N     =  2e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
#define maxBits 22
#define maxMask (1<<maxBits)
 
ll n,b[N],a[N];
vll s;

int main(){
    fastio;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    for(int i = 0; i < n; i++) s.push_back(a[i]-b[i]);
    sort(s.begin(), s.end());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll d = a[i] - b[i];
        if(d > 0) ans--;
        auto it = upper_bound(s.begin(), s.end(),-d)-s.begin();
        ans += n-it;
    }
    cout<<ans/2<<endl;
}