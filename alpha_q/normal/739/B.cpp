#include <bits/stdc++.h>
 
using namespace std;

const int N = 200010;

struct edge {
    int to;
    long long cost;

    edge () {}
    edge (int a, long long b) : to(a), cost(b) {}
};

vector <edge> g[N];
int n, l[N], r[N];
long long a[N], b[N], dist[N];
int preOrder[N], pointer = 0;
vector <long long> t[N + N];

void dfs (int u, int par) {
    preOrder[++pointer] = u;
    l[u] = pointer;
    for (edge e : g[u]) {
        if (e.to == par) continue;
        dist[e.to] = dist[u] + e.cost;
        dfs(e.to, u);
    }
    r[u] = pointer;
    b[u] = dist[u] - a[u];
}

void init (void) {
    for (int i = n - 1; i; --i) {
        int l = i << 1, r = l | 1;
        t[i].resize((int) t[l].size() + t[r].size());
        merge(t[l].begin(), t[l].end(), t[r].begin(), t[r].end(), t[i].begin());
    }
}

int query (int l, int r, long long v) {
    int ret = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            int tot = upper_bound(t[l].begin(), t[l].end(), v) - t[l].begin();
            ret += tot;
            ++l;
        }
        if (r & 1) {
            --r;
            int tot = upper_bound(t[r].begin(), t[r].end(), v) - t[r].begin();
            ret += tot;
        }
    }
    return ret;
}

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    for (int v = 2; v <= n; ++v) {
        int u; long long w;
        scanf("%d %lld", &u, &w);
        g[u].push_back(edge(v, w));
        g[v].push_back(edge(u, w));
    }

    dfs(1, 0);

    for (int i = 0; i < n; ++i) 
        t[n + i].push_back(b[preOrder[i + 1]]);
    init();
    
    for (int i = 1; i <= n; ++i) {
        int res = query(l[i], r[i], dist[i]);
        printf("%d ", res);
    }
    puts("");
    return 0;
}