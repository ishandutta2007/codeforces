#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define lSon (node << 1)
#define rSon (lSon | 1)
#define inf (1LL << 60)

int def;
vector< pair<int, int> > list[maxN << 3];
int id[maxN];

struct aint {
    int n;
    vector<int> nodes;

    void build(int node, int l, int r) {
        if (l == r) {
            id[l] = node;
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        list[lSon].pb(mp(node, 0));
        list[rSon].pb(mp(node, 0));

        list[node + def].pb(mp(lSon + def, 0));
        list[node + def].pb(mp(rSon + def, 0));
    }

    void get_nodes(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) {
            nodes.pb(node);
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid)
            get_nodes(lSon, l, mid, qL, qR);
        if (qR > mid)
            get_nodes(rSon, mid + 1, r, qL, qR);
    }
};

int n, q, s, n1, n2, i;
int tp, x, y, l, r, w;
aint work;
ll dist[maxN << 3];
priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > H;


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &q, &s);
    def = n << 2;
    work.n = n;
    work.build(1, 1, n);
    work.nodes.reserve(n << 2);

    for (i = 1; i <= n; i++) {
        list[ id[i] ].pb(mp(def + id[i], 0));
        list[ def + id[i] ].pb(mp(id[i], 0));
    }

    for (i = 1; i <= q; i++) {
        scanf("%d", &tp);

        if (tp == 1) {
            scanf("%d%d%d", &x, &y, &w);
            list[id[x]].pb(mp(def + id[y], w));
        }

        if (tp == 2) {
            scanf("%d%d%d%d", &x, &l, &r, &w);
            work.nodes.clear();
            work.get_nodes(1, 1, n, l, r);

            for (auto e : work.nodes)
                list[id[x]].pb(mp(e + def, w));
        }

        if (tp == 3) {
            scanf("%d%d%d%d", &x, &l, &r, &w);
            work.nodes.clear();
            work.get_nodes(1, 1, n, l, r);

            for (auto e : work.nodes)
                list[e].pb(mp(id[x] + def, w));
        }
    }

    for (i = 1; i <= 8 * n; i++)
        dist[i] = inf;

    dist[ id[s] ] = 0;
    H.push(mp(0, id[s] ));

    ll dd;
    int node;

    while (!H.empty()) {
        dd = H.top().first;
        node = H.top().second;
        H.pop();

        if (dist[node] != dd) continue;

        for (auto to : list[node]) {
            if (dist[to.first] > dist[node] + to.second) {
                dist[to.first] = dist[node] + to.second;
                H.push(mp(dist[to.first], to.first));
            }
        }
    }

    for (i = 1; i <= n; i++) {
        x = id[i];

        if (dist[x] >= inf)
            dist[x] = -1;
        printf("%lld ", dist[x]);
    }



    return 0;
}