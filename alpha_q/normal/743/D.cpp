#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const long long INF = 1e17 + 10;

vector <int> g[N];
int n, flat[N];
int l[N], r[N], tot = 0;
long long c[N], cost[N];
long long t[N + N];
long long ret = -INF;

void dfs (int u, int p) {
    flat[++tot] = u;
    l[u] = tot;
    cost[u] = c[u];
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
        cost[u] += cost[v];
    }
    r[u] = tot;
}

void init (void) {
    for (int i = n - 1; i; --i) {
        t[i] = max(t[i << 1], t[i << 1 | 1]);
    }
}

long long query (int l, int r) {
    long long res = -INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, t[l++]);
        if (r & 1) res = max(res, t[--r]);
    }
    return res;
}

void go (int u, int p) {
    int x = l[u] - 1, y = r[u] - 1;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v == p) continue;
        int w = l[v] - 1, z = r[v] - 1;
        long long a = query(w, z + 1);
        long long b = max(query(x + 1, w), query(z + 1, y + 1));
        // cout << u << " " << v << ": " << a << " " << b << endl;
        ret = max(ret, a + b);
        go(v, u);
    }
}

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", c + i);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; ++i) {
        // cout << flat[i] << " ";
        t[n + i - 1] = cost[flat[i]];
    }
    // cout << endl;
    init();
    // for (int i = 1; i <= n; ++i) cout << cost[i] << " "; cout << endl;
    // for (int i = 1; i <= n; ++i) {
    //     cout << i << " : " << l[i] << " " << r[i] << endl;
    // }
    go(1, 1);
    if (ret <= -INF/2) puts("Impossible"); 
    else printf("%lld\n", ret);
    return 0;
}