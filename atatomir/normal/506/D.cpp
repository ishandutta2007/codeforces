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

#define maxN 100011

const int limit = 453;

int n, m, q, i, x, y, col;
vector< pair<int, int> > edges[maxN];
pair<int, int> Q[maxN];

vector<int> cols[maxN];
int sz[maxN];

int id_big[maxN], cnt_big;

int dad[maxN];
vector<int> who[maxN];

int big[limit + 11][maxN];

bool us[maxN];
vector<int> appear[maxN];
int groups;



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

void pre() {
    int i;

    for (i = 1; i <= n; i++) {
        dad[i] = i;

        sort(cols[i].begin(), cols[i].end());
        cols[i].resize(unique(cols[i].begin(), cols[i].end()) - cols[i].begin());

        sz[i] = cols[i].size();

        if (sz[i] >= limit)
            id_big[i] = ++cnt_big;
    }
}

void solve_color(int id) {
    for (auto e : edges[id])
        Merge(e.first, e.second);

    for (auto e : edges[id]) {
        if (!us[e.first])
            who[Find(e.first)].pb(e.first);
        if (!us[e.second])
            who[Find(e.second)].pb(e.second);
        us[e.first] = us[e.second] = true;
    }

    for (auto e : edges[id]) {
        int node = e.first;
        if (who[e.second].size() > 0) node = e.second;

        if (who[node].size() > 0) {
            groups++;
            for (auto n1 : who[node]) {
                appear[n1].pb(groups);
                if (sz[n1] < limit) continue;
                for (auto n2 : who[node])
                    big[id_big[n1]][n2]++;
            }

            who[node].clear();
        }
    }

    for (auto e : edges[id])
        dad[e.first] = e.first, dad[e.second] = e.second, us[e.first] = us[e.second] = false;
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &col);
        edges[col].pb(mp(x, y));
        cols[x].pb(col);
        cols[y].pb(col);
    }

    pre();

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y);
        Q[i] = mp(x, y);
    }

    for (i = 1; i <= m; i++) {
        if (edges[i].empty()) continue;
        solve_color(i);
    }

    for (i = 1; i <= q; i++) {
        if (sz[Q[i].first] > sz[Q[i].second]) swap(Q[i].first, Q[i].second);
        if (sz[Q[i].second] < limit) {

            int c0 = 0;
            int c1 = 0;
            int n1 = Q[i].first;
            int n2 = Q[i].second;
            int ans = 0;

            while (c0 < appear[n1].size() && c1 < appear[n2].size()) {
                if (appear[n1][c0] == appear[n2][c1]) {
                    ans++;
                    c0++; c1++;
                    continue;
                }

                if (appear[n1][c0] < appear[n2][c1])
                    c0++;
                else
                    c1++;
            }

            printf("%d\n", ans);
            continue;
        }

        printf("%d\n", big[ id_big[Q[i].second] ][Q[i].first]);
    }


    return 0;
}