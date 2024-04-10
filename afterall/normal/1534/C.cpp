#include <bits/stdc++.h>
/// this time?
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=4e5+100;
ll a[N];
ll b[N];
ll par[N];
bool vis[N];
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
ll mod=1e9+7;
ll Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        par[i]=i;
        cin >> a[i];
        vis[i]=0;
    }
    for (int i=1;i<=n;i++){
        cin >> b[i];
        par[b[i]]=getpar(a[i]);
    }
    ll ans=1;
    for (int i=1;i<=n;i++){
        if (vis[getpar(i)]==0){
            vis[getpar(i)]=1;
            ans*=2;
            ans%=mod;
        }
    }
    kill(ans);
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}