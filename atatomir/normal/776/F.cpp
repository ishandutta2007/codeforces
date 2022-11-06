#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

struct edge {
    int x, y, id;

    bool operator<(const edge& who)const {
        return mp(x, y) < mp(who.x, who.y);
    }

    bool operator==(const edge& who) {
        return mp(x, y) == mp(who.x, who.y);
    }
};

int n, m, i, x, y;
vector< pair<int, int> > diag;

int nxt[maxN], pre[maxN];

int cnt;
vector<int> region[maxN];
vector<edge> E;

int target;
vector<int> list[maxN];
int color[maxN];
int down[maxN];

vector<int> id;


int asso(int x, int y) {
    if (x < y) swap(x, y);
    return min(x - y - 1, n - (x - y - 1) - 2);
}

void zone(int a, int b) {
    int node;

    cnt++;
    //if (a < b) {
        for (node = a; node != b; node = nxt[node]) {
            region[cnt].pb(node);
            E.pb({node, nxt[node], cnt});
        }
        region[cnt].pb(b);

        E.pb({a, b, cnt});
        nxt[a] = b;
        pre[b] = a;
    /*} else {
        for (node = a; node != b; node = pre[node]) {
            region[cnt].pb(node);
            E.pb({node, pre[node], cnt});
        }
        region[cnt].pb(a);

        E.pb({a, b, cnt});
        nxt[b] = a;
        pre[a] = b;
    }*/

}

void build_tree() {
    int i, j;

    for (i = 1; i <= n; i++) nxt[i] = i + 1, pre[i] = i - 1;
    nxt[n] = 1;
    pre[1] = n;

    sort(diag.begin(), diag.end(), [](const pair<int, int>& a, const pair<int, int>& b)->bool const {
        return asso(a.first, a.second) < asso(b.first, b.second);
    });

    for (auto e : diag) {
        if (e == diag.back()) {
            zone(e.first, e.second);
            zone(e.second, e.first);
        } else {
            int a = e.first;
            int b = e.second;

            if (b - a - 1 <= n - (b - a - 1) - 2)
                zone(a, b);
            else
                zone(b, a);
        }
    }

    for (auto& e : E)
        if (e.x > e.y)
            swap(e.x, e.y);

    sort(E.begin(), E.end());
    for (i = 0; i < E.size(); i = j) {
        for (j = i; j < E.size(); j++)
            if (!(E[i] == E[j]))
                break;

        if (i + 1 == j) continue;
        list[E[i].id].pb(E[i + 1].id);
        list[E[i + 1].id].pb(E[i].id);
    }

}

void refresh(vector<int>& v) {
    int i;

    for (i = 0; i < v.size(); i++) {
        if (color[v[i]]) {
            v[i] = v.back();
            v.pop_back(); i--;
            continue;
        }
    }
}

void dfs1(int node, int root) {
    down[node] = 1;

    refresh(list[node]);
    for (auto to : list[node]) {
        if (to == root) continue;
        dfs1(to, node);
        down[node] += down[to];
    }
}

int dfs2(int node, int root) {
    bool ok = (target - down[node]) <= target / 2;

    for (auto to : list[node]) {
        if (to == root) continue;

        if (down[to] > target / 2) ok = false;
        int ans = dfs2(to, node);
        if (ans) return ans;
    }

    if (ok) return node;
    return 0;
}

void color_tree(int node, int col) {

    dfs1(node, 0);
    target = down[node];

    node = dfs2(node, 0);

    color[node] = col;
    for (auto to : list[node])
        color_tree(to, col + 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        diag.pb(mp(x, y));
    }

    if (m == 0) {
        printf("1");
        return 0;
    }

    build_tree();
    color_tree(1, 1);

    for (i = 1; i <= cnt; i++) {
        sort(region[i].begin(), region[i].end());
        reverse(region[i].begin(), region[i].end());
        id.pb(i);
    }

    sort(id.begin(), id.end(), [](int a, int b)->bool const {
        static int i;

        for (i = 0; region[a][i] == region[b][i]; i++);
        return region[a][i] < region[b][i];
    });

    for (auto e : id)
        printf("%d ", color[e]);


    return 0;
}