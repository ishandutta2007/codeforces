#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = (int) 2e5 + 7;
vector <int> g[MAXN];
ll ans = 0;
int dp[MAXN];
int n, k, u, v;

void dfs(int v, int pr) {
    for (auto to : g[v]) {
        if (to != pr) {
            dfs(to, v);
            ans += min(dp[to], 2 * k - dp[to]);
            dp[v] += dp[to];
        }
    }
}

int main() {    
    scanf("%d%d", &n, &k);
    for (int i = 0; i < 2 * k; i++) {
        scanf("%d", &v);
        dp[v] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    printf("%lld\n", ans);
}