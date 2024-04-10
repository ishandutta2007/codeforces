#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
int mod = 1e9+7;
const int maxn = 2009;
int dp[maxn][maxn];
int sz = 0;
struct line{
    int k, b;
};
line kb[maxn];
int intersect(line a, line b){
    if (a.k - b.k == 0)
        return 1e12;
    return (b.b - a.b) / (a.k - b.k);
}
void add_line(line a){
    while(sz > 1){
        line b1, c;
        b1 = kb[sz - 1];
        c = kb[sz - 2];
        if (intersect(a, b1) > intersect(b1, c))
            break;
        sz--;
    }
    kb[sz] = a;
    sz++;
}
bool cmp(line x, line y){
    return x.k < y.k;
}
signed main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> a(n);
    vector<pair<pair<int, int>, int>> e(m * 2);
    for(int i = 0; i < m; ++i){
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        e[i] = {{v, u}, w};
        e[i + m] = {{u, v}, w};
        a[v].push_back({u, w});
        a[u].push_back({v, w});
    }
    for(int i = 0; i < maxn; ++i)
        for(int v = 0; v < maxn; ++v)
            dp[i][v] = -1e12;
    int ans = 0;
    dp[0][0] = 0;
    for(int i = 1; i < maxn; ++i){
        for(int v = 0; v < n; ++v)
            for(auto u: a[v])
                dp[i][u.f] = max(dp[i - 1][v] + u.s, dp[i][u.f]);
    }
    if (q < maxn){
        for(int i = 1; i <= q; ++i){
            int ans1 = 0;
            for(int v = 0; v < n; ++v)
                ans1 = max(ans1, dp[i][v]);
            ans += ans1;
            ans %= mod;
        }
        cout << ans;
        return 0;
    }
    for(int i = 1; i < maxn; ++i){
            int ans1 = 0;
            for(int v = 0; v < n; ++v)
                ans1 = max(ans1, dp[i][v]);
            ans += ans1;
            ans %= mod;
        }
    vector<line> l;
    for(int i = 0; i < m * 2; ++i)
        if (dp[n][e[i].f.f] >= 0)
            l.push_back({e[i].s, dp[n][e[i].f.f] - n * e[i].s});
    sort(l.begin(), l.end(), cmp);
    vector<line> l2;
    l2.push_back(l[0]);
    for(int i = 1; i < l.size(); ++i){
        if (l[i].k != l2.back().k)
            l2.push_back(l[i]);
        else
            l2.back().b = max(l[i].b, l2.back().b);
    }
    for(int i = 0; i < l2.size(); ++i)
        add_line(l2[i]);
    vector<int> p;
    for(int i = 1; i < sz; ++i){
        p.push_back(intersect(kb[i - 1], kb[i]));
    }
    p.push_back(1e12);
    int cur = maxn;
    int i = 0;
    while(cur <= q){
        while(p[i] < cur)
            i++;
        int t = min(p[i], q);
        int cnt = (t - cur + 1) % mod;
        int k1 = (kb[i].k + mod) % mod, b1 = (kb[i].b + mod) % mod;
        ans += b1 * cnt % mod + ((cnt * (cur + cur + cnt - 1) / 2) % mod * k1) % mod;
        ans %= mod;
        cur = t + 1;
    }
    cout << ans;
    return 0;
}