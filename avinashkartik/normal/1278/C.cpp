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
 
const ll   N     =  3e+5+7;
const ll   MAXN  =  1e+9;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,a[N],l[N],r[N];
um ml,mr;

int main(){
    fastio;
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        n = 2*n;
        for(int i = 1; i <= n; i++) {
            cin>>a[i];
            if(a[i] == 2) a[i] = -1;
        }
        ll ans = n;
        l[0] = 0;
        r[n+1] = 0;
        for(ll i = 1; i <= n/2; i++){
            l[i] = l[i-1] + a[i];
            ml[l[i]] = i;
            if(l[i] == 0) ans = min(ans,n-i);
        }
        for(ll i = n; i > n/2; i--){
            r[i] = r[i+1] + a[i];
            mr[r[i]] = i;
            if(r[i] == 0) ans = min(ans,i-1);
        }
        if(l[n/2] + r[n/2+1] == 0) ans = 0;
        else if(r[n/2+1] == 0) ans = n/2;
        else if(l[n/2] == 0) ans = n/2;
        //cout<<ans<<" ";
        for(int i = 1; i <= n/2; i++)
            if(mr[-l[i]] != 0) {
                //cout<<mr[-l[i]]<<" "<<i<<endl;
                ans = min(ans,mr[-l[i]]-i-1);
            }
        for(int i = n-1; i > n/2; i--)
            if(ml[-r[i]] != 0) {
                //cout<<mr[-l[i]]<<" "<<i<<endl;
                ans = min(ans,i-ml[-r[i]]-1);
            }
        cout<<ans<<endl;
        mr.clear();
        ml.clear();
        fill_n(r,n+3,0);
        fill_n(l,n+3,0);
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}