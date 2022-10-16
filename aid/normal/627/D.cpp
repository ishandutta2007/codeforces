#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200 * 1000 + 5, MAXX = 1000 * 1000 + 5;
int a[MAXN], dp0[MAXN], dp1[MAXN];
char used[MAXN], ok[MAXN];
vector<int> g[MAXN];

int dfs(int v, int m) {
    used[v] = true;
    ok[v] = true;
    dp0[v] = 1;
    dp1[v] = 1;
    int maxbad0 = 0, maxbad1 = 0, res = 0;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if(used[u])
            continue;
        if(a[u] < m) {
            ok[v] = false;
            continue;
        }
        res = max(res, dfs(u, m));
        if(ok[u]) {
            dp0[v] += dp0[u];
            dp1[v] += dp1[u];
        }
        else {
            ok[v] = false;
            if(dp0[u] > maxbad0) {
                maxbad1 = maxbad0;
                maxbad0 = dp0[u];
            }
            else if(dp0[u] > maxbad1)
                maxbad1 = dp0[u];
        }
    }
    dp0[v] += maxbad0;
    dp1[v] += maxbad0 + maxbad1;
    res = max(res, dp1[v]);
    return res;
}

bool solve(int n, int m, int k) {
    for(int i = 0; i < n; i++) {
        used[i] = false;
        ok[i] = false;
        dp0[i] = 0;
        dp1[i] = 0;
    }
    bool foundGood = false, foundBad = false;
    for(int i = 0; i < n; i++)
        if(a[i] >= m && !used[i]) {
            foundGood = true;
            bool okv = false;
            for(size_t j = 0; j < g[i].size(); j++)
                if(a[g[i][j]] < m)
                    okv = true;
            if(okv)
                foundBad = true;
            if(okv && dfs(i, m) >= k)
                return true;
        }
    if(foundGood && !foundBad)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int l = 0, r = MAXX;
    while(l < r - 1) {
        int m = (l + r) / 2;
        if(solve(n, m, k))
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
    return 0;
}