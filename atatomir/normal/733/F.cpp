#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011
#define maxLog 19

struct edge {
    int x, y;
    ll w, c;
    int id;

    bool operator<(const edge& who)const {
        return w < who.w;
    }
};

int n, m, i, j;
edge E[maxN];
ll w[maxN];
int dad[maxN];
int lvl[maxN];

int up[maxLog][maxN];
pair<ll, int> val_up[maxLog][maxN];

vector< pair<int, ll> > list[maxN];
ll mst_cost, B;
pair<ll, int> best_edge;
ll ans;

int ch, mi;
bool used[maxN];



int Find(int x) {
    if (dad[x] == x) return x;
    dad[x] = Find(dad[x]);
    return dad[x];
}

bool Merge(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) return false;

    dad[x] = y;
    return true;
}

void dfs(int node, int root) {
    for (auto to : list[node]) {
        if (root == to.first) continue;

        lvl[to.first] = lvl[node] + 1;
        up[0][to.first] = node;
        val_up[0][to.first] = mp(w[to.second], to.second);
        dfs(to.first, node);
    }
}

pair<ll, int> go_up(int &node, int how) {
    pair<ll, int> ans = mp(-1, -1);

    for (int i = 0; how > 0; i++, how >>= 1)
        if (how & 1)
            ans = max(ans, val_up[i][node]), node = up[i][node];

    return ans;
}

ll on_way(int x, int y) {
    pair<ll, int> ans = mp(-1, -1);

    if (lvl[x] < lvl[y]) swap(x, y);
    ans = go_up(x, lvl[x] - lvl[y]);

    if (x == y) return ans.second;

    for (int i = maxLog - 1; i >= 0; i--)
        if (up[i][x] != up[i][y])
            ans = max(ans, max(val_up[i][x], val_up[i][y])), x = up[i][x], y = up[i][y];

    ans = max(ans, max(val_up[0][x], val_up[0][y]));
    return ans.second;
}

bool cmp(const edge& a, const edge& b) {
    return a.id < b.id;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) scanf("%lld", &E[i].w), w[i] = E[i].w, E[i].id = i;
    for (i = 1; i <= m; i++) scanf("%lld", &E[i].c);
    for (i = 1; i <= m; i++) scanf("%d%d", &E[i].x, &E[i].y);
    scanf("%lld", &B);

    sort(E + 1, E + m + 1);
    for (i = 1; i <= n; i++) dad[i] = i;

    best_edge = mp(1LL << 60, -1);
    for (i = 1; i <= m; i++) {
        if (Merge(E[i].x, E[i].y) == false) continue;
        mst_cost += E[i].w;
        best_edge = min(best_edge, mp(E[i].c, E[i].id));

        list[E[i].x].pb(mp(E[i].y, E[i].id));
        list[E[i].y].pb(mp(E[i].x, E[i].id));
        used[E[i].id] = true;
    }

    ans = mst_cost - (B / best_edge.first);
    ch = best_edge.second; mi = 0;

    dfs(1, 0);
    for (i = 1; i < maxLog; i++) {
        for (j = 1; j <= n; j++) {
            up[i][j] = up[i - 1][ up[i - 1][j] ];
            val_up[i][j] = max(val_up[i - 1][j], val_up[i - 1][ up[i - 1][j] ]);
        }
    }

    for (i = 1; i <= m; i++) {
        ll act = on_way(E[i].x, E[i].y);
        ll new_cost = mst_cost - w[act] + E[i].w - (B / E[i].c);
        if (new_cost < ans) {
            ans = new_cost;
            ch = E[i].id;
            mi = act;
        }
    }

    sort(E + 1, E + m + 1, cmp);

    printf("%lld\n", ans);
    for (i = 1; i <= m; i++) {
        if (mi == i) continue;
        if (used[i] && ch != i) {
            printf("%d %lld\n", i, E[i].w);
            continue;
        }

        if (ch == i) {
            printf("%d %lld\n", i, E[i].w - (B / E[i].c));
            continue;
        }
    }


    return 0;
}