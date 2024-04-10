#include <bits/stdc++.h>

using namespace std;

#define int long long
vector < int > g[100005];
int dp[100005];
int a[100005];
int ans;

void dfs(int v, int sum){
    //cout << v << " " << sum << endl;
    if (a[v] != -1){
        if (a[v] < sum){
            cout << -1 << endl;
            exit(0);
        }
    }
    int imin = 1e12;
    for (auto u : g[v]){
        dfs(u, max(sum, a[v]));
        imin = min(imin, dp[u]);
    }
    if (a[v] != -1) dp[v] = min(imin, a[v]);
    else dp[v] = imin;
}

void dfs1(int v, int sum){
    //cout << v << " " << sum << " ";
    int imin;
    if (a[v] != -1) imin = min(a[v] - sum, dp[v]);
    else imin = dp[v] - sum;
    if (imin >= 1e10) imin = 0;
    ans += imin;
    //cout << imin << endl;
    for (auto u : g[v]) dfs1(u, sum + imin);
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 2; i <= n; ++i){
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) dp[i] = 1e9;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1, 0);
    dfs1(1, 0);
    cout << ans << endl;
    return 0;
}