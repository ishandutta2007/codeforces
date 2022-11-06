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

#define maxN 400011

int n, m, i;
pair<int, int> E[maxN];
vector< pair<int, int> > list[maxN];

bool us[maxN];
int lvl[maxN];

vector<int> st;
vector<int> to[maxN];
vector<int> from[maxN];

int cnt;
int prov[maxN];
pair<int, int> best;
int act_nr;

int ans;


void dfs(int node, int root) {
    us[node] = true;

    for (auto e : list[node]) {
        int to = e.first;

        if (to == root) continue;

        if (!us[to]) {
            lvl[to] = lvl[node] + 1;
            E[e.second] = mp(node, to);
            dfs(to, node);
        } else {
            if (lvl[to] >= lvl[node] - 1) continue;

            E[e.second] = mp(node, to);
        }
    }
}

void dfs_to(int node) {
    us[node] = true;

    for (int e : to[node])
        if (!us[e])
            dfs_to(e);

    st.pb(node);
}

void dfs_from(int node) {
    prov[node] = cnt;
    act_nr++;

    for (int e : from[node])
        if (prov[e] == 0)
            dfs_from(e);
}

void dfs_solve(int node) {
    us[node] = true;

    for (auto e : list[node]) {
        int to = e.first;

        if (us[to]) continue;

        if (prov[node] != prov[to])
            E[e.second] = mp(to, node);
        dfs_solve(to);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &E[i].first, &E[i].second);
        list[E[i].first].pb(mp(E[i].second, i));
        list[E[i].second].pb(mp(E[i].first, i));
    }

    // make graph directed
    dfs(1, 0);

    // get strong connected comps
    for (i = 1; i <= m; i++) {
        to[E[i].first].pb(E[i].second);
        from[E[i].second].pb(E[i].first);
    }
    memset(us, 0, sizeof(us));
    for (i = 1; i <= n; i++)
        if (!us[i])
            dfs_to(i);

    reverse(st.begin(), st.end());
    for (auto e : st) {
        if (prov[e] > 0) continue;

        act_nr = 0;
        cnt++;
        dfs_from(e);

        best = max(best, mp(act_nr, e));
    }

    ans = best.first;

    memset(us, 0, sizeof(us));
    dfs_solve(best.second);

    printf("%d\n", ans);
    for (i = 1; i <= m; i++)
        printf("%d %d\n", E[i].first, E[i].second);


    return 0;
}