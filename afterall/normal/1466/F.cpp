#include <bits/stdc++.h>
/// 500 485
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=5e5+100;
ll vis[N];
ll c[N];
ll par[N];
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
int Main(){
    for (int i=0;i<N;i++){
        par[i]=i;
    }
    ll n,m;
    cin >> n >> m;
    vector <int> ans;
    for (int i=1;i<=n;i++){
        ll k;
        cin >> k;
        vector <int> b;
        for (int j=0;j<k;j++){
            ll x;
            cin >> x;
            x=getpar(x);
            if (x!=0)
                b.pb(x);
        }
        if (b.size()==0) continue;
        if (b.size()==2 && b[0]==b[1]) continue;
        if (b.size()==1){
            ans.pb(i);
            par[getpar(b[0])]=0;
        }
        if (b.size()==2){
            ans.pb(i);
            par[getpar(b[0])]=getpar(b[1]);
        }
    }
    ll mod=1e9+7;
    ll y=1;
    for (int i=0;i<ans.size();i++){
        y*=(ll)2;
        y%=mod;
    }
    cout << y << " " << ans.size() << endl;
    for (auto u : ans){
        cout << u << " ";
    }
    cout << endl;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while (t--) Main();
}