#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
vector <pii> g[N];
ll dis[N];
ll out[N];
ll n;
map <pii,int> mp;
int dij(){
    memset(dis,61,sizeof dis);
    dis[n]=0;
    set <pii> s;
    s.insert({0,n});
    while(s.size()){
        ll v=s.begin()->S;
        s.erase(s.begin());
        for (auto U : g[v]){
            ll u=U.F;
            //cout << v << " dfv " << u << endl;
            if (dis[u]>dis[v]+out[u]){
                s.erase({dis[u],u});
                dis[u]=dis[v]+out[u];
                s.insert({dis[u],u});
            }
            out[u]-=1;
        }
    }
    return dis[1];
}
void Main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        out[i]=0;
        g[i].clear();
    }
    ll m;
    cin >> m;
    for (int i=1;i<=m;i++){
        ll u,v;
        cin >> u >> v;
        g[v].pb({u,0});
        out[u]++;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<g[i].size();j++){
            g[i][j].S=out[g[i][j].F]-mp[{i,g[i][j].F}]+1;
        }
    }
    cout << dij() << endl;

}
int32_t main(){
    sync;
    ll q=1;
    //cin >> q;
    while(q--) Main();
}