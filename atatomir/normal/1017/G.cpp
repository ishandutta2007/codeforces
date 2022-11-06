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

const int maxN = 100011;
const int sz = 1200;

int n, q, i, x;
vector<int> list[maxN], adj[maxN];
pair<int, int> Q[maxN];

bool spec[maxN];
int lvl[maxN], up[maxN];

/*
* push_down - adancime neagra in grupa actuala
* lazy - adaugari ulterioare de la ultima propagare
* rm_down - lazy pentru operatia de stergere
* any_rm - daca a fost vreo stergere in grupa actuala
* sum - suma de negre inainte
*/

int push_down[maxN], lazy[maxN], sum[maxN];
bool rm_down[maxN], any_rm[maxN];
vector<int> way;

bool act[maxN];


int dfs(int node) {
    vector<int> here = {};

    for (auto to : list[node]) {
        lvl[to] = lvl[node] + 1;
        sum[to] = sum[node];
        int v = dfs(to);
        if (v != 0) here.pb(v);
    }

    if (spec[node] == false && here.size() > 1) spec[node] = true;
    if (spec[node] == true) {
        for (auto e : here) {
            adj[node].pb(e);
            up[e] = node;
        }
        return node;
    } else {
        if (here.empty()) return 0;
        return here[0];
    }

}

void dfs_sum(int node) {
    sum[node] += (act[node] == 1);
    for (auto to : list[node]) {
        sum[to] = sum[node];
        dfs_sum(to);
    }
}

void propagate(int node) {
    static int bef;

    if (rm_down[node]) {
        for (auto to : adj[node]) {
            push_down[to] = lazy[to] = 0;
            rm_down[to] = any_rm[to] = true;
        }
        rm_down[node] = false;
    }

    if (lazy[node] == 0) return;

    for (auto to : adj[node]) {
        if (any_rm[node])
            bef = 0;
        else
            bef = sum[to] - sum[node] - (act[to] == true ? 1 : 0);

        bef = min(lvl[to] - lvl[node], bef + push_down[node] - lazy[node]);
        bef = max(0, bef + lazy[node] - (lvl[to] - lvl[node]));

        lazy[to] += bef;
        push_down[to] += bef;
    }
    lazy[node] = 0;
}

void get_way(int x) {
    way.clear();
    for (int node = x; node != 1; node = up[node])
        way.pb(node);

    propagate(1);
    for (int i = way.size() - 1; i >= 0; i--)
        propagate(way[i]);
}

void upd_push(int x) {
    lazy[x]++;
    push_down[x]++;
}

void upd_rm(int x) {
    rm_down[x] = true;
    any_rm[x] = true;

    lazy[x] = push_down[x] = 0;
}

void query(int x) {
    if (push_down[x] > 0)
        printf("black\n");
    else
        printf("white\n");
}

void dfs_big(int node, int cnt, bool rmv) {
    if (spec[node]) {
        propagate(node);
        cnt = push_down[node];
        rmv = any_rm[node];
    }

    if (act[node] == false || rmv == true) {
        act[node] = false;
        if (cnt > 0) {
            act[node] = true;
            cnt--;
        }
    }

    for (auto to : list[node])
        dfs_big(to, cnt, rmv);
}

void solve_bucket(int l, int r) {
    int i, j;

    for (i = 1; i <= n; i++) {
        spec[i] = 0;
        adj[i].clear();
        push_down[i] = lazy[i] = sum[i] = 0;
        rm_down[i] = any_rm[i] = false;
    }

    spec[1] = true;
    for (i = l; i <= r; i++)
        spec[Q[i].second] = true;

    dfs(1);

    for (i = 1; i <= n; i++)
        if (spec[i] && act[i] == true)
            push_down[i] = 1, act[i] = false;

    dfs_sum(1);

    for (i = l; i <= r; i++) {
        get_way(Q[i].second);
        if (Q[i].first == 1) upd_push(Q[i].second);
        if (Q[i].first == 2) upd_rm(Q[i].second);
        if (Q[i].first == 3) query(Q[i].second);
    }

    dfs_big(1, 0, false);
}

void gen() {
    freopen("test.in", "w", stdout);

    n = q = 100000;
    printf("%d %d\n", n, q);
    for (i = 2; i <= n; i++)
        printf("%d ", (rand() % (i - 1)) + 1);
    for (i = 1; i <= q; i++) {
        printf("\n%d %d", 1 + (rand() % 3), 1 + (rand() % n));
    }


    exit(0);
}

int main()
{
    //gen();
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);

    scanf("%d%d", &n, &q);
    for (i = 2; i <= n; i++) {
        scanf("%d", &x);
        list[x].pb(i);
    }
    for (i = 1; i <= q; i++) scanf("%d%d", &Q[i].first, &Q[i].second);

    for (i = 1; i <= q; i += sz) {
        solve_bucket(i, min(q, i + sz - 1));
    }


    return 0;
}