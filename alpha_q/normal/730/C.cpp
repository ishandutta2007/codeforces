#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

struct data {
    long long c, k, p;
    bool operator < (const data &d) const {
        return p < d.p;
    }
};

data x[N];
vector <int> g[N];
int n, m, w, q, d[N][N];

bool ok (int tot, int to, long long r, long long a) {
    for (int i = 1; i <= w; ++i) {
        if (d[to][x[i].c] > tot or d[to][x[i].c] < 0) continue;
        long long shovel = min(x[i].k, r);
        if (x[i].p * shovel > a) return 0;
        a -= x[i].p * shovel, r -= shovel;
        if (r == 0) return 1;
    }
    return 0;
}

void bfs (int z) {
    queue <int> q;
    d[z][z] = 0, q.push(z);
    while (not q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (d[z][v] == -1) {
            d[z][v] = d[z][u] + 1;
            q.push(v);
        }
    }
}

int main (int argc, char const *argv[]) {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%d", &w);
    for (int i = 1; i <= w; ++i)
        scanf("%lld %lld %lld", &x[i].c, &x[i].k, &x[i].p);
    sort(x + 1, x + w + 1);
    memset(d, -1, sizeof d);
    for (int i = 1; i <= n; ++i) bfs(i);

    scanf("%d", &q); while (q--) {
        int to; long long r, a;
        scanf("%d %lld %lld", &to, &r, &a);
        int lo = 0, hi = n - 1, res = -1;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            if (ok(mid, to, r, a)) res = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        printf("%d\n", res);
    }
    return 0;
}