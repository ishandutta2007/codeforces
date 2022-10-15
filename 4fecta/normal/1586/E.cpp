#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 300005;

int n, m, u, v, q, par[MN], p[MN], dep[MN], cnt[MN], id = 1, vis[MN], lvs;
vector<pii> a[MN];
pii e[MN];
pii qs[MN];

int find(int x) {return x == par[x] ? x : par[x] = find(par[x]);}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    return true;
}

void dfs(int cur, int pre, int d) {
    dep[cur] = d;
    p[cur] = pre;
    for (pii nxt : a[cur]) {
        if (nxt.s == pre) continue;
        dfs(nxt.f, nxt.s, d + 1);
    }
}

void dfs(int cur, int pre) {
    if (a[cur].size() % 2) lvs++;
    vis[cur] = 1;
    for (pii nxt : a[cur]) {
        if (nxt.f == pre) continue;
        dfs(nxt.f, cur);
    }
}

int get_nxt(int x, int i) {
    return e[i].f == x ? e[i].s : e[i].f;
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (merge(u, v)) {
            a[u].push_back({v, id});
            a[v].push_back({u, id});
            e[id++] = {u, v};
        }
    }
    dfs(1, 0, 0);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> qs[i].f >> qs[i].s;
        int x = qs[i].f, y = qs[i].s;
        while (p[x] != p[y]) {
            if (dep[x] > dep[y]) cnt[p[x]]++, x = get_nxt(x, p[x]);
            else cnt[p[y]]++, y = get_nxt(y, p[y]);
        }
    }
    int odd = false;
    for (int i = 1; i < id; i++) if (cnt[i] % 2) odd = true;
    if (!odd) {
        printf("YES\n");
        for (int i = 1; i <= q; i++) {
            int x = qs[i].f, y = qs[i].s;
            vector<int> v1, v2;
            while (x != y) {
                if (dep[x] > dep[y]) v1.push_back(x), x = get_nxt(x, p[x]);
                else v2.push_back(y), y = get_nxt(y, p[y]);
            }
            reverse(v2.begin(), v2.end());
            printf("%lld\n", (int) (v1.size() + 1 + v2.size()));
            for (int p : v1) printf("%lld ", p);
            printf("%lld", x);
            for (int p : v2) printf(" %lld", p);
            printf("\n");
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 1; i < id; i++) {
        if (cnt[i] % 2) {
            a[e[i].f].push_back({e[i].s, i});
            a[e[i].s].push_back({e[i].f, i});
        }
    }
    printf("NO\n");
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        lvs = 0;
        dfs(i, 0);
        ans += lvs / 2;
    }
    printf("%lld\n", ans);

    return 0;
}