#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int n, m, k;
const int maxn = 300000;
int used[maxn], t[maxn], up[maxn], s[maxn], c1[maxn], w[maxn], x[maxn], y[maxn], c[maxn], cnt[maxn], c_all[maxn], dp[maxn], ans[maxn], cnt2[maxn];
vector<int> g[maxn];
vector<pair<int, int>> g2[maxn];
int t1 = 0;
void dfs(int v){
    t[v] = t1;
    t1++;
    used[v] = 1;
    for(auto u: g[v])
        if(!used[u])
            dfs(u);
}
void dfs2(int v, int pr){
    used[v] = 1;
    for(auto u: g[v])
        if(!used[u])
            dfs2(u, v);
    up[v] = t[v];
    for(auto u: g[v]){
        if(t[u] > t[v])
            up[v] = min(up[v], up[u]);
        else if(u != pr)
            up[v] = min(up[v], t[u]);
    }
}
void dfs3(int v, int c2){
    c1[v] = c2;
    for(auto u: g[v]){
        if(c1[u] == -1 && ((t[v] < t[u] && up[u] <= t[v]) || (t[v] > t[u] && t[u] >= up[v])))
            dfs3(u, c2);
    }
}
void count_dp(int v){
    used[v] = 1;
    cnt2[v] = cnt[v];
    dp[v] = c_all[v];
    for(auto [u, w1]: g2[v])
        if(!used[u]){
            count_dp(u);
            if(cnt2[u] == k || cnt2[u] == 0)
                dp[v] += dp[u];
            else
                dp[v] = max(dp[v], dp[v]+dp[u]-w1);
            cnt2[v] += cnt2[u];
        }
}
void count_ans(int v, int pr, int w2){
    used[v] = 1;
    if(pr != -1){
        if(cnt2[v] == k || cnt2[v] == 0)
            dp[pr] -= dp[v];
        else
            dp[pr] = min(dp[pr], dp[pr]-dp[v]+w2);
        if(cnt2[v] == 0 || cnt2[v] == k)
            dp[v] += dp[pr];
        else
            dp[v] = max(dp[v], dp[v]+dp[pr]-w2);
    }
    ans[v] = dp[v];
    for(auto [u, w1]: g2[v])
        if(!used[u])
            count_ans(u, v, w1);
    if(pr != -1){
        if(cnt2[v] == 0 || cnt2[v] == k)
            dp[v] -= dp[pr];
        else
            dp[v] = min(dp[v], dp[v]-dp[pr]+w2);
        if(cnt2[v] == k || cnt2[v] == 0)
            dp[pr] += dp[v];
        else
            dp[pr] = max(dp[pr], dp[pr]+dp[v]-w2);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i)
        cin >> s[i], s[i]--;
    for(int i = 0; i < n; ++i)
        cin >> c[i];
    for(int i = 0; i < m; ++i)
        cin >> w[i];
    for(int i = 0; i < m; ++i){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        g[x[i]].pb(y[i]);
        g[y[i]].pb(x[i]);
    }
    dfs(0);
    for(int i = 0; i < n; ++i)
        used[i] = 0;
    dfs2(0, -1);
    for(int i = 0; i < n; ++i)
        c1[i] = -1;
    int c2 = 0;
    for(int i = 0; i < n; ++i)
        if(c1[i] == -1)
            dfs3(i, c2), c2++;
    for(int i = 0; i < k; ++i)
        cnt[c1[s[i]]]++;
    for(int i = 0; i < n; ++i)
        c_all[c1[i]] += c[i];
    for(int i = 0; i < m; ++i)
        if(c1[x[i]] != c1[y[i]])
            g2[c1[x[i]]].pb({c1[y[i]], w[i]}), g2[c1[y[i]]].pb({c1[x[i]], w[i]});
    for(int i = 0; i < n; ++i)
        used[i] = 0;
    count_dp(0);
    for(int i = 0; i < n; ++i)
        used[i] = 0;
    count_ans(0, -1, -1);
    for(int i = 0; i < n; ++i)
        cout << ans[c1[i]] << ' ';
    return 0;
}