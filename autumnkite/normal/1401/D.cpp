#include <bits/stdc++.h>

const int P = 1000000007;

int n, m;
std::vector<int> E[100005];
int sz[100005];

void dfs(int u, int fa = 0) {
    sz[u] = 1;
    for (int v : E[u]) {
        if (v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        E[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(1);
    std::vector<long long> v;
    for (int i = 2; i <= n; ++i) {
        v.push_back(1ll * sz[i] * (n - sz[i]));
    }
    std::sort(v.begin(), v.end());
    scanf("%d", &m);
    std::vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &p[i]);
    }
    while (m < n - 1) {
        p.push_back(1);
        ++m;
    }
    std::sort(p.begin(), p.end());
    while (m > n - 1) {
        --m;
        p[m - 1] = 1ll * p[m - 1] * p[m] % P;
        p.pop_back();
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans = (ans + v[i] % P * p[i]) % P;
    }
    printf("%d\n", ans);
}

int main() {
    int T = 1;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}