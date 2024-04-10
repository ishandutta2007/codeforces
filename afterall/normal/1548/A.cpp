#include <bits/stdc++.h>
/// 500 485 462 A4
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
const int N=2e5+100;
ll vis[N];
set <int> s[N];
ll ans=0;
int Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        s[u].insert(v);
        s[v].insert(u);
        if (u>v) swap(u,v);
        if (vis[u]==1) continue;
        vis[u]=1;
        ans++;
    }
    ll q;
    cin >> q;
    while(q--){
        ll t;
        cin >> t;
        if (t==2){
            ll u,v;
            cin >> u >> v;
            s[u].erase(v);
            s[v].erase(u);
            if (u>v) swap(u,v);
            if (vis[u]==0) continue;
            if (s[u].size()==0){
                vis[u]=0;
                ans--;
                continue;
            }
            if (*s[u].rbegin()<u){
                vis[u]=0;
                ans--;
            }
        }
        if (t==1){
            ll u,v;
            cin >> u >> v;
            s[u].insert(v);
            s[v].insert(u);
            if (u>v) swap(u,v);
            if (vis[u]) continue;
            vis[u]=1;
            ans++;
        }
        if (t==3) cout << n-ans << endl;
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--) Main();
}