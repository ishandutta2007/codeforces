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
ll M[N];
vector <int> g[N];
ll vis[N];
ll po=1;
ll h[N];
ll mex(ll v){
    po++;
    for (auto u : g[v]){
       // if (v==1) cout << u << " d " << M[u] << " " << vis[0] << " " << po << endl;
        vis[M[u]]=po;
    }
    for (int i=0;i<N;i++){
        if (vis[i]!=po) return i;
    }
}
ll t[N];
ll in[N];
int32_t main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> h[i];
    for (int i=0;i<m;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        in[v]++;
    }
    vector <int> ras;
    queue <int> q;
    for (int i=1;i<=n;i++){
        if (in[i]==0) q.push(i);
    }
    while(q.size()){
        ll v=q.front();
        ras.pb(v);
        q.pop();
        for (auto u : g[v]){
            in[u]--;
            if (in[u]==0) q.push(u);
        }
    }
    reverse(ras.begin(),ras.end());
    for (auto u : ras){
        M[u]=mex(u);
        t[M[u]] ^= h[u];
    }
    for (int i=N-1;i>-1;i--){
        if (t[i]){
        cout << "WIN" << endl;
        ll v=0;
        for (int j=1;j<=n;j++){
            if (M[j]==i){
                ll z=t[M[j]] ^ h[j];
                if (z<h[j]){
                    h[j]=z;
                    v=j;
                    break;
                }
            }
        }
    //    cout << v << " " << M[v] << endl;
        for (auto u : g[v]){
            if (t[M[u]]){
                t[M[u]] ^= h[u];
                h[u]=t[M[u]];
                t[M[u]]=0;
            }
        }
        for (int i=1;i<=n;i++){
            cout << h[i] << " ";
        }
        return 0;
        }
    }
    kill("LOSE");

}