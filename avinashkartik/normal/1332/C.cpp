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
 
ll t=1,n,a[N],k;
um m;;
string s;

int main(){
    fastio;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>s;
        ll ans = 0;
        for(int i = 0,ri = k-1; i <= ri; i++,ri--){
            m.clear();
            ll f = 1;
            for(int j = i; j < n; j += k){
                m[s[j]-'a']++;
            }
            if(i != ri){
                f = 2;
                for(int j = ri; j < n; j += k){
                    m[s[j]-'a']++;
                }
            }
            ll maxx = 0;
            for(auto it : m){
                maxx = max(maxx,it.y);
            }
            //cout<<maxx<<" ";
            ans += f*n/k-maxx;
        }
        cout<<ans<<"\n";
    }
}