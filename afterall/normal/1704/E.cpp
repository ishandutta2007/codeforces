#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define endl '\n'
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
vector <int> g[N];
ll in[N];
ll a[N];
ll mod=998244353;
void Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        g[i].clear();
        in[i]=0;
    }

    for (int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        in[v]++;
    }
    vector <int> ras;
    queue <int> q;
    for (int i=1;i<=n;i++){
        if (in[i]==0){
            q.push(i);
        }
    }
    while(q.size()){
        ll v=q.front();
        ras.pb(v);
        q.pop();
        for (auto u : g[v]){
            in[u]--;
            if (in[u]==0){
                q.push(u);
            }
        }
    }
    ll p1=0,ans=0;
    for (int i=1;i<=n;i++){
        p1=0;
        for (int j=n-1;j>-1;j--){
            int v=ras[j];
            if (a[v]==0) continue;
            p1=1;
            a[v]--;
            for (auto u : g[v]){
                a[u]++;
            }
        }
        if (p1==0){
            cout << ans << endl;
            return;
        }
        ans++;
    }
    for (int i=1;i<=n;i++) a[i]%=mod;
    ll mx=a[ras[0]];
    for (int i=0;i<n;i++){
        int v=ras[i];
        for (auto u : g[v]){
            a[u]+=a[v];
            a[u]%=mod;
            mx=max(mx,a[u]);
        }
    }
    cout << (ans+a[ras[n-1]])%mod << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}