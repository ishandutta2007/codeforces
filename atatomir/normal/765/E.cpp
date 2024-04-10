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

int n, i, x, y, R;
vector<int> list[maxN];

int down[maxN], up[maxN], dist[maxN];
vector<int> aux;

int tp[maxN];
bool ok;

void dfs1(int node, int root) {
    down[node] = 1;

    for (auto to : list[node])
        if (to != root)
            dfs1(to, node), down[node] = max(down[node], down[to] + 1);
}

void dfs2(int node, int root) {

    aux.clear();
    for (auto to : list[node])
        if (to != root)
            aux.pb(to);

    if (aux.empty()) return;

    sort(aux.begin(), aux.end(), [](int a, int b)->bool const {
        return down[a] > down[b];
    });

    if (aux.size() == 1) {
        up[aux[0]] = up[node] + 1;
        dfs2(aux[0], node);
        return;
    }

    up[aux[0]] = max(up[node] + 1, down[aux[1]] + 2);
    for (i = 1; i < aux.size(); i++)
        up[aux[i]] = max(up[node] + 1, down[aux[0]] + 2);

    for (auto e : list[node])
        if (e != root)
            dfs2(e, node);
}

int do_it(int x) {
    while (x % 2 == 0)
        x >>= 1;

    return x;
}

void solve(int node, int root) {
    for (auto to : list[node])
        if (to != root && ok)
            solve(to, node);

     if (!ok) return;

    aux.clear();
    for (auto to : list[node])
        if (to != root)
            aux.pb(tp[to] + 1);

    sort(aux.begin(), aux.end());
    aux.resize(unique(aux.begin(), aux.end()) - aux.begin());

    if (aux.empty()) {
        tp[node] = 0;
        return;
    }

    if (aux.size() > 2) {
        ok = false;
        return;
    }

    if (aux.size() >= 2 && node != R) {
        ok = false;
        return;
    }

    tp[node] = aux[0];
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs1(1, 0);

    up[1] = 0;
    dfs2(1, 0);

    for (i = 1; i <= n; i++) dist[i] = max(up[i], down[i]);
    R = min_element(dist + 1, dist + n + 1) - dist;

    for (i = 1; i <= n; i++) {
        if (dist[i] != dist[R]) continue;
        R = i;

        ok = true;
        solve(R, 0);

        if (ok) {
            int ans = 0;
            for (auto e : aux)
                ans += e;

            ans = do_it(ans);

            printf("%d", ans);
            return 0;
        }
    }

    printf("-1");



    return 0;
}