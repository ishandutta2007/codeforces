#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

const int bucket = 400;

struct edge {
    int x, y;
    int id;
};

int n, q, i, j, cnt, deny;
edge E[maxN];
pair<int, int> edg[maxN];
map< pair<int, int>, int > M;
int on[maxN], last[maxN];
vector<int> ids;

vector<int> list[maxN];
bool good = true;

int gr[maxN], col[maxN], cnt_gr;
int dad[maxN], down[maxN];

int Find(int x) {
    if (dad[x] == x) return x;
    x = Find(dad[x]);
    return dad[x];
}

bool Merge(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) return false;
    if (down[x] > down[y]) swap(x, y);
    dad[x] = y;
    down[y] = max(down[y], down[x] + 1);
    return true;
}

void dfs(int node) {
    for (auto to : list[node]) {
        if (gr[to] && col[to] == col[node]) good = false;
        if (gr[to]) continue;

        gr[to] = gr[node];
        col[to] = col[node] ^ 1;
        dfs(to);
    }
}

void build_graph() {
    int i;

    for (i = 1; i <= n; i++) list[i].clear();
    for (i = 1; i <= cnt; i++) {
        if (!on[i]) continue;
        if (last[i] == deny) continue;

        list[edg[i].first].pb(edg[i].second);
        list[edg[i].second].pb(edg[i].first);
    }

    good = true;
    memset(gr, 0, sizeof(gr));
    cnt_gr = 0;

    for (i = 1; i <= n; i++) {
        if (gr[i]) continue;

        gr[i] = ++cnt_gr;
        dfs(i);
    }
}

bool combine(int x, int y) {
    int gr_x = gr[x];
    int gr_y = gr[y];
    int inv_gr_x = gr[x] + cnt_gr;
    int inv_gr_y = gr[y] + cnt_gr;

    if (col[x] != col[y]) {
        x = gr_x;
        y = gr_y;
        int xx = inv_gr_x;
        int yy = inv_gr_y;

        Merge(x, y);
        Merge(xx, yy);

        if (Find(x) == Find(xx)) return false;
        if (Find(y) == Find(yy)) return false;
    } else {
        x = gr_x;
        y = gr_y;
        int xx = inv_gr_x;
        int yy = inv_gr_y;

        Merge(x, yy);
        Merge(xx, y);

        if (Find(x) == Find(xx)) return false;
        if (Find(y) == Find(yy)) return false;
    }

    return true;
}

bool check() {
    int i, x, y;

    //! init only useful components
    //! there may be more than 2 * sqrt comps in the graph
    for (auto z : ids) {
        auto e = edg[z];
        e.first = gr[e.first];
        e.second = gr[e.second];

        dad[e.first] = e.first;
        dad[e.first + cnt_gr] = e.first + cnt_gr;
        down[e.first] = 0;
        down[e.first + cnt_gr] = 0;

        dad[e.second] = e.second;
        dad[e.second + cnt_gr] = e.second + cnt_gr;
        down[e.second] = 0;
        down[e.second + cnt_gr] = 0;
    }

    for (auto e : ids) {
        if (!on[e]) continue;

        x = edg[e].first;
        y = edg[e].second;

        if (!combine(x, y))
            return false;
    }

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &E[i].x, &E[i].y);
        if (E[i].x > E[i].y) swap(E[i].x, E[i].y);
        if (M[mp(E[i].x, E[i].y)] == 0) M[mp(E[i].x, E[i].y)] = ++cnt, edg[cnt] = mp(E[i].x, E[i].y);
        E[i].id = M[mp(E[i].x, E[i].y)];
    }

    for (i = 1; i <= q; i += bucket) {
        ids.clear();
        deny = i;

        for (j = 0; j < bucket && i + j <= q; j++) {
            if (last[ E[i + j].id ] != deny) {
                last[ E[i + j].id ] = deny;
                ids.pb(E[i + j].id);
            }
        }

        build_graph();
        for (j = 0; j < bucket && i + j <= q; j++) {
            on[E[i + j].id] ^= 1;
            if (!good) {
                printf("NO\n");
            } else {
                if (check())
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }


    return 0;
}