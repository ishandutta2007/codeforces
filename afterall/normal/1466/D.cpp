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
const int N=2e5+100;
vector <int> g[N];
ll vis[N];
ll val[N];
int Main(){
    ll n;
    cin >> n;
    vector <pii> ras;
    ll ans=0;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        ans+=x;
        ras.pb({x,i});
    }
    sort(ras.begin(),ras.end());
    reverse(ras.begin(),ras.end());
    for (int i=0;i<n+3;i++){
        g[i].clear();
        vis[i]=0;
    }
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll cnt=0;
    ll t=0;
    cout << ans << " ";
    ll last=ans;
    ll p1=0;
    for (int i=2;i<=n-1;i++){
        while(cnt<i-1){
            if (t>ras.size()-1) {
                p1=1;
                break;
            }
            ll v=ras[t].S;
            t++;
            ll z=g[v].size();
            if (v==ras[0].S) z--;
            else z-=1;
            if (z<=0) continue;
            cnt+=z;
        }
        if (p1==0)
        ans+=ras[t-1].F;
        cout << ans << " ";
    }
    cout << endl;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while (t--) Main();
}