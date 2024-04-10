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
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;;
ll h[N];
ll ans = 0;
vector<int> G[N];

int DFS(int u, int p){
    ll mx = h[u];
    vector<int> V = {0};
    for(auto adj : G[u]){
        if(adj == p) continue;
        V.pb(DFS(adj, u));
        mx = max(mx, (ll) V.back());
    }
    sort(V.begin(),V.end()); reverse(V.begin(),V.end());
    ans += max(0ll, h[u] - V[0]);

    if(p == -1)
        ans += max(0ll, h[u] - V[1]);
    return mx;
}
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    ll mx = 1;
    for(int i = 2; i <= n; i++) if(h[mx] < h[i]) mx = i;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    DFS(mx, -1);
    cout << ans << '\n';
    return 0;
}