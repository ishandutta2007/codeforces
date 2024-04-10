#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll a[N];
ll b[N];
ll par[N];
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
vector <pair <int,pii> > yal;
ll Main(){
    ll m,n;
    cin >> m >> n;
    for (int i=1;i<=m;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        cin >> b[i];
    }
    for (int i=0;i<N;i++) par[i]=i;
    ll z=0;
    for (int i=1;i<=m;i++){
        ll k;
        cin >> k;
        for (int j=1;j<=k;j++){
            ll x;
            cin >> x;
            yal.pb({b[x]+a[i],{i,x+m}});
            z+=b[x]+a[i];
        }
    }
    sort(yal.begin(),yal.end());
    reverse(yal.begin(),yal.end());
    ll ans=0;
    for (int i=0;i<yal.size();i++){
        ll u=yal[i].S.F,v=yal[i].S.S;
        ll uu=u,vv=v;
        u=getpar(u);
        v=getpar(v);
        if (u!=v){
           // cout << uu << " " << vv << endl;
            par[u]=v;
            ans+=yal[i].F;
        }
    }

    cout << z-ans << endl;
}
int32_t main(){
    sync;
    ll t;
    t=1;
    while(t--) Main();
}