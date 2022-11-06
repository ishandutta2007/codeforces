#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011
#define lSon (node << 1)
#define rSon (lSon | 1)

const int limit = 30;

struct edge {
    int x, y, v;
};

struct query {
    int tp, x, y, v;
};

struct cyc_base {
    int data[limit];

    cyc_base() {
        memset(data, 0, sizeof(data));
    }

    void init() {
        memset(data, 0, sizeof(data));
    }

    int reduce(int x) {
        for (int i = limit - 1; i >= 0; i--) {
            if (x & (1 << i))
                x ^= data[i];
        }

        return x;
    }

    void add(int x) {
        x = reduce(x);
        if (x == 0) return;

        int i;
        for (i = limit - 1; (1 << i) > x; i--);
        data[i] = x;
    }
};

struct dsu {
    int n, i;
    int dad[maxN];
    int depth[maxN];
    int way[maxN];
    vector< pair<int*, int> > rollbacks;

    void init(int _n) {
        n = _n;
        rollbacks.clear();
        for (i = 1; i <= n; i++) {
            dad[i] = i;
            depth[i] = 0;
            way[i] = 0;
        }
    }

    int Find(int x) {
        while (dad[x] != x) x = dad[x];
        return x;
    }

    int get_value(int x) {
        int ans = 0;

        while (x != dad[x]) {
            ans ^= way[x];
            x = dad[x];
        }

        return ans;
    }

    bool Merge(int x, int y, int v) {
        int wx, wy;

        wx = get_value(x);
        wy = get_value(y);
        x = Find(x);
        y = Find(y);

        if (x == y) return false;

        if (depth[x] < depth[y]) swap(x, y), swap(wx, wy);

        rollbacks.pb(mp(&dad[y], dad[y]));
        rollbacks.pb(mp(&depth[x], depth[x]));
        rollbacks.pb(mp(&way[y], way[y]));

        dad[y] = dad[x];
        depth[x] = max(depth[x], 1 + depth[y]);
        way[y] = v ^ wx ^ wy;
        return true;
    }


};

int n, m, q, i;
edge E[maxN], rez[maxN * 2];
query Q[maxN];

struct aint {
    vector< vector<edge> > data;
    dsu forest;

    void init(int sz) {
        data = vector< vector<edge> >(sz * 4 + 11, vector<edge>(0));
        forest.init(n);
    }

    void upd(int node, int l, int r, int qL, int qR, edge e) {
        if (qL <= l && r <= qR) {
            data[node].pb(e);
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) upd(lSon, l, mid, qL, qR, e);
        if (qR > mid) upd(rSon, mid + 1, r, qL, qR, e);
    }

    void solve(int node, int l, int r, cyc_base& base) {
        int keep = forest.rollbacks.size();
        cyc_base aux;

        aux = base;
        for (auto e : data[node]) {
            if (!forest.Merge(e.x, e.y, e.v)) {
                aux.add( forest.get_value(e.x) ^ forest.get_value(e.y) ^ e.v );
            }
        }

        if (l == r) {
            if (l < m) return;
            l -= m;
            if (Q[l].tp != 3) return;

            int path = forest.get_value(Q[l].x) ^ forest.get_value(Q[l].y);
            path = aux.reduce(path);

            printf("%d\n", path);

            return;
        }

        int mid = (l + r) >> 1;
        solve(lSon, l, mid, aux);
        solve(rSon, mid + 1, r, aux);

        while (forest.rollbacks.size() > keep) {
            auto last = forest.rollbacks.back();
            forest.rollbacks.pop_back();
            *last.first = last.second;
        }
    }
};

map< pair<int, int>, pair<int, int> > M;
aint work;

int main()
{
    //freopen("test.in","r",stdin);

    /*freopen("test.out", "w", stdout);
    n = 200000;
    cout << n << ' ' << n - 1 << '\n';
    for (i = 1; i < n; i++) cout << i << ' ' << i + 1 << ' ' << 17 << '\n';
    cout << ((n - 2) / 2) * 2 << '\n';
    for (i = 1; i <= (n - 2) / 2; i++) {
        cout << 1 << ' ' << i << ' ' << i + 2 << ' ' << 38 << '\n';
        cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
    }
    return 0;*/

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        edge aux;
        scanf("%d%d%d", &aux.x, &aux.y, &aux.v);
        E[i] = aux;

        M[mp(aux.x, aux.y)] = mp(i, aux.v);
        rez[i] = E[i];
    }

    scanf("%d", &q);
    work.init(m + q);

    for (i = 1; i <= q; i++) {
        query aux;
        scanf("%d%d%d", &aux.tp, &aux.x, &aux.y);
        Q[i] = aux;

        if (aux.tp == 1) {
            scanf("%d", &aux.v);
            M[mp(aux.x, aux.y)] = mp(m + i, aux.v);
            rez[i + m] = {aux.x, aux.y, aux.v};
        }

        if (aux.tp == 2) {
            auto pr = mp(aux.x, aux.y);
            work.upd(1, 1, m + q, M[pr].first, m + i, {aux.x, aux.y, M[pr].second});
            M[pr] = mp(0, 0);
        }


    }

    for (auto e : M) {
        if (e.second == mp(0, 0)) continue;
        work.upd(1, 1, m + q, e.second.first, m + q, rez[e.second.first]);
    }

    cyc_base aux; aux.init();
    work.solve(1, 1, m + q, aux);


    return 0;
}