#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second                
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,m,x,a[N],suf[N],pre[N];
set <ll> s;
vll ans;

void solve(){
    cin>>n;
    memset(pre,0,sizeof(pre));
    memset(suf,0,sizeof(suf));
    for(int i = 0 ; i < n; i++) cin>>a[i];
    s.clear();
    ans.clear();
    for(int i = 0 ; i < n; i++){
        s.insert(a[i]);
        auto it = s.end();
        it--;
        if(s.size() == i+1 && (*it) == i+1)
            pre[i] = 1;
    }
    s.clear();
    for(int i = n-1 ; i >= 0; i--){
        s.insert(a[i]);
        auto it = s.end();
        it--;
        if(s.size() == n-i && (*it) == n-i)
            suf[i] = 1;
    }
    for(int i = 0 ; i < n-1; i++){
        if(pre[i] == 1 && suf[i+1] == 1)
            ans.push_back(i+1);
    }
    cout<<ans.size()<<endl;
    for(auto i : ans)
        cout<<i<<" "<<n-i<<endl;
}

int main(){
    fastio;
    cin>>t;
    while(t--){
        solve();
    }
}