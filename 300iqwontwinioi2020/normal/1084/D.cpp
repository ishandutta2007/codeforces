#include <bits/stdc++.h>

using namespace std;

long long POWER (long long x, long long y, long long z){
    long long pas = 1, p = x;
    while (y){
        if ((y & 1))
            pas = pas * p % z;
        y /= 2;
        p = p * p % z;
    }
    return pas;
}

const long long N = 300005;

long long n;
long long a[N];
long long dp[N], d[N];
long long b[N];
long long DP[N];
long long ans;
vector < long long > g[N], gg[N], v[N];

void dfs1 (long long k, long long p){
    b[k] = -1;
    for (long long i = 0; i < (long long)g[k].size(); i++)
        if (g[k][i] != p){
            long long to = g[k][i];
            dfs1 (to, k);
            if (dp[to] + a[to] > gg[k][i])
                v[k][i] = dp[to] + a[to] - gg[k][i];
            d[k] = max (d[k], v[k][i]);
            if (d[k] > dp[k])
                swap (d[k], dp[k]);
        }
        else
            b[k] = i;
}

void dfs2 (long long k, long long p){
    if (b[k] != -1)
        if (v[k][b[k]] > d[k])
            d[k] = v[k][b[k]];
    if (d[k] > dp[k])
        swap (d[k], dp[k]);
    for (long long i = 0; i < (long long)g[k].size(); i++){
        long long to = g[k][i];
        if (to == p)
            continue;
        long long x = dp[k];
        if (x == v[k][i])
            x = d[k];
        if (x + a[k] - gg[k][i] > 0)
            v[to][b[to]] = x + a[k] - gg[k][i];
        dfs2 (to, k);
    }
    ans = max (ans, dp[k] + a[k]);
}


int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (long long i = 1; i <= n; i++)
        cin>>a[i];
    for (long long i = 1; i < n; i++){
        long long u, v, x;
        cin>>u>>v>>x;
        g[u].push_back (v);
        g[v].push_back (u);
        gg[u].push_back (x);
        gg[v].push_back (x);
    }
    for (long long i = 1; i <= n; i++)
        for (long long j = 0; j < (long long)g[i].size(); j++)
            v[i].push_back (0);
    dfs1 (1, 0);
    dfs2 (1, 0);
    cout<<ans<<endl;
    return 0;
}