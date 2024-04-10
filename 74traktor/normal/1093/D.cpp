#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod = 998244353;
vector < int > g[300005];
int use[300005];
int l, r;
bool f;

int st(int a, int b){
    if (b == 0) return 1;
    if (b % 2 == 0){
        int q = st(a, b / 2);
        return q * q % mod;
    }
    return a * st(a, b - 1) % mod;
}

int dfs(int v, int tt){
    use[v] = tt;
    if (tt % 2 == 0) l++;
    else r++;
    for (auto u : g[v]){
        if (use[u] == 0) dfs(u, tt % 2 + 1);
        else{
            if (use[u] == use[v]) f = false;
        }
    }
}


main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m,x, y;
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> n >> m;
        for (int j = 0; j <= n; ++j) g[j].clear();
        for (int j = 0; j < m; ++j){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for (int j = 0; j <= n; ++j) use[j] = 0;
        f = true;
        l = 0;
        r = 0;
        int ans = 1;
        for (int v = 1; v <= n; ++v){
            if (use[v] == 0){
                dfs(v, 1);
                ans *= ((st(2, r) + st(2, l) % mod));
                ans %= mod;
                l = 0;
                r = 0;
            }
        }
        if (!f) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}