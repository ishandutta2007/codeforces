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

ll n,k,a[N],pre[N],suf[N],fct[N],bct[N],fval=-1,bval=-1;
set <ll> s;
um m;

int main(){
    cin>>n>>k;
    ll n1 = n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        s.insert(a[i]);
        m[a[i]]++;
    }
    n = s.size();
    ll i = 0;
    for(auto it : s){
        a[i++] = it;
        if(m[it] >= k){
            cout<<0;
            exit(0);
        }
    }
    pre[0] = m[a[0]];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + m[a[i]];
        fct[i] = fct[i-1] + pre[i-1]*(a[i]-a[i-1]);
        if(fval == -1 && pre[i] >= k){
            fval = fct[i]-(pre[i]-k);
        }
    }
    suf[n-1] = m[a[n-1]];
    for(int i = n-2; i >= 0; i--){
        suf[i] = suf[i+1] + m[a[i]];
        bct[i] = bct[i+1] + suf[i+1]*(a[i+1]-a[i]);
        if(bval == -1 && suf[i] >= k){
            bval = bct[i]-(suf[i]-k);
        }
    }
    ll ans = min(fval,bval);
    for(int i = 0; i < n; i++){
        ll res = fct[i]+bct[i]-n1+k;
        ans = min(ans,res);
    }
    cout<<ans<<endl;
}