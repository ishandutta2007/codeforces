#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
vector<vector<int>> g;
int n;
vector<int> k1, used;
int mod = 1000000007;
int dfs(int v){
    used[v] = 1;
    int d = 1;
    for(auto u: g[v])
        if(!used[u])
            d += dfs(u);
    if(v != 0)
        k1.pb(d*(n-d));
    return d;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        g.assign(n, vector<int>(0));
        k1.clear();
        used.assign(n, 0);
        for(int i = 0; i < n-1; ++i){
            int v, u;
            cin >> v >> u;
            v--, u--;
            g[v].pb(u);
            g[u].pb(v);
        }
        int m;
        cin >> m;
        vector<int> p(m);
        for(int i = 0; i < m; ++i)
            cin >> p[i];
        sort(all(p));
        vector<int> r(n-1);
        if(m <= n-1){
            for(int i = 0; i < m; ++i)
                r[i] = p[i];
            for(int i = m; i < n-1; ++i)
                r[i] = 1;
        }else{
            for(int i = 0; i < n-2; ++i)
                r[i] = p[i];
            r[n-2] = 1;
            for(int i = n-2; i < m; ++i)
                r[n-2] *= p[i], r[n-2] %= mod;
        }
        sort(all(r));
        dfs(0);
        sort(all(k1));
        int ans = 0;
        for(int i = 0; i < n-1; ++i)
            r[i] %= mod, k1[i] %= mod, ans = ans+r[i]*k1[i], ans %= mod;
        cout << ans << '\n';
    }
    return 0;
}