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

#define maxN 500011

const int limit = 500000;

struct edge {
    int x, y, w;
    int id;
};

int n, m, x, y, w, i, j, k, q;
edge E[maxN];
vector<edge> W[maxN];
vector< pair<int, vector<int> >  > Q[maxN];
vector<int> aux;

int dad[maxN];
int h[maxN];
bool bad[maxN];

vector< pair<int, int> > ch_dad, ch_h;

bool cmp(int a, int b) {
    return E[a].w < E[b].w;
}

void add_query(int id) {
    int i, j;
    vector<int> act;

    sort(aux.begin(), aux.end(), cmp);
    for (i = 0; i < aux.size(); i = j) {
        act.clear();
        for (j = i; j < aux.size(); j++) {
            if (E[aux[i]].w != E[aux[j]].w)
                break;
            act.pb(aux[j]);
        }

        Q[E[aux[i]].w].pb(mp(id, act));
    }
}

int Find(int x) {
    if (dad[x] == x) return x;
    return Find(dad[x]);
}

bool Merge(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return false;
    if (h[a] < h[b]) swap(a, b);

    ch_dad.pb(mp(b, dad[b]));
    dad[b] = a;

    ch_h.pb(mp(a, h[a]));
    h[a] = max(h[a], 1 + h[b]);

    return true;
}

void refr() {
    for (auto e : ch_dad)
        dad[e.first] = e.second;
    for (auto e : ch_h)
        h[e.first] = e.second;
}

bool check(vector<int>& edges) {
    int x, y;

    ch_dad.clear();
    ch_h.clear();

    for (auto id : edges) {
        x = E[id].x;
        y = E[id].y;

        if (!Merge(x, y)) {
            refr();
            return false;
        }
    }

    refr();

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &E[i].x, &E[i].y, &E[i].w);
        E[i].id = i;
        W[E[i].w].pb(E[i]);
    }

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d", &k);
        aux = vector<int>(k);
        for (auto &e : aux)
            scanf("%d", &e);

        add_query(i);
    }

    for (i = 1; i <= n; i++) {
        dad[i] = i;
        h[i] = 0;
    }

    for (i = 1; i <= limit; i++) {
        for (auto& e : Q[i]) {
            if (bad[e.first]) continue;
            if (!check(e.second))
                bad[e.first] = true;
        }

        for (auto e : W[i])
            Merge(e.x, e.y);
    }

    for (i = 1; i <= q; i++) {
        if (bad[i])
            cout << "NO\n";
        else
            cout << "YES\n";
    }


    return 0;
}