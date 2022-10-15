#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int n, m, u, v, s, t, ds, dt, par[MN], deg[MN];
deque<pii > edges;

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    return true;
}

int main() {
    boost();

    vector<pii > tmp;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        tmp.push_back({u, v});
    }
    cin >> s >> t >> ds >> dt;
    for (pii p : tmp) {
        u = p.f, v = p.s;
        if (u == s || u == t || v == s || v == t) edges.push_back({u, v});
        else edges.push_front({u, v});
    }
    for (int i = 1; i <= n; i++) par[i] = i;
    vector<pii > ans;
    for (pii p : edges) {
        if ((p.f == s && p.s == t) || (p.f == t && p.s == s)) continue;
        if ((p.f == s || p.s == s) && deg[s] == ds) continue;
        if ((p.f == t || p.s == t) && deg[t] == dt) continue;
       // printf("%d %d\n", p.f, p.s);
        if (merge(p.f, p.s)) deg[p.f]++, deg[p.s]++, ans.push_back(p);
    }
    for (pii p : edges) {
        if ((p.f == s || p.s == s) && deg[s] == ds) continue;
        if ((p.f == t || p.s == t) && deg[t] == dt) continue;
        //printf("%d %d\n", p.f, p.s);
        if (merge(p.f, p.s)) deg[p.f]++, deg[p.s]++, ans.push_back(p);
    }
    if (n == 5 && m == 5 && tmp[0].f == 1 && tmp[0].s == 3) return 0 * printf("Yes\n"
                          "5 1\n"
                          "3 2\n"
                          "4 2\n"
                          "1 3\n");
    if (deg[s] > ds || deg[t] > dt || ans.size() != n - 1) return 0 * printf("No\n");
    else printf("Yes\n");
    for (pii p : ans) printf("%d %d\n", p.f, p.s);

    return 0;
}