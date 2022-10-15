#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct elf {
    int u, v, p;
};

const int MN = 200005;

int t, n, m, u, v, w, dep[MN];
elf a[MN];
elf b[MN];
pii parent[MN];

void make_set(int v) {
    parent[v] = make_pair(v, 0);
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

bool add_edge(int a, int b, int t) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;
    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;
    if (a == b) {
        if (x ^ y ^ t) return false;
        else return true;
    } else {
        parent[b] = make_pair(a, x ^ y ^ t);
        return true;
    }
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            make_set(i);
        }
        bool bad = 0;
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> w;
            if (w != -1) {
                int p = __builtin_popcount(w) & 1;
                if (!add_edge(u, v, p)) bad = 1;
            }
            a[i] = {u, v, w};
        }
        for (int i = 1; i <= m; i++) {
            cin >> u >> v >> w;
            b[i] = {u, v, w};
            if (!add_edge(u, v, w)) bad = 1;
        }
        if (bad) {
            printf("NO\n");
            continue;
        }
        for (int i = 1; i < n; i++) {
            if (a[i].p != -1) continue;
            pair<int, int> pu = find_set(a[i].u);
            u = pu.first;
            int x = pu.second;
            pair<int, int> pv = find_set(a[i].v);
            v = pv.first;
            int y = pv.second;
            if (u == v) {
                a[i].p = x ^ y;
            } else a[i].p = 0;
            if (!add_edge(a[i].u, a[i].v, a[i].p)) bad = 1;
        }
        if (bad) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for (int i = 1; i < n; i++) printf("%lld %lld %lld\n", a[i].u, a[i].v, a[i].p);
    }

    return 0;
}