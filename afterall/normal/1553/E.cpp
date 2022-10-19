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
const int N=3e5+100;
ll t[N];
ll a[N];
ll nxt[N];
ll vis[N];
ll n,m;
void dfs(ll v){
    if (vis[v]==0) vis[v]=1;
    else return ;
    dfs(nxt[v]);
}
bool check(ll x){
    for (int i=1;i<=n;i++){
        ll z=a[i]+x;
        if (z>n) z-=n;
        nxt[i]=z;
    }
    ll ans=0;
    for (int i=1;i<=n;i++) vis[i]=0;
    for (int i=1;i<=n;i++){
        if (vis[i]==0) dfs(i),ans++;
    }
    if (n-ans<=m) return 1;
    return 0;
}
int Main(){

    cin >> n;

    cin >> m;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a[i]=x;
        ll z=i-x+n;
        if (z>=n) z-=n;
        t[z]++;
    }
    vector <int> ans;
    for (int i=0;i<n;i++){
      //  cout << t[i] << endl;
        if (t[i]>=n/3) if (check(i)) ans.pb(i);
    }
    cout << ans.size() << " ";
    for (auto u : ans) cout << u << " ";
    cout << endl;
    return 0;

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}