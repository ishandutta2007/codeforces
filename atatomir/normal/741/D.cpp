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
#define maxVal ((1 << 22) + 3)

int n, i, x;
char c;
vector< pair<int, char> > list[maxN];

int lvl[maxN], cnt[maxN];
int conf[maxN];

int down[maxVal];
vector<int>* nodes[maxN];
int sol[maxN];
int sigma = 0;

bool cmp(const pair<int, char>& a,const pair<int, char>& b) {
    return cnt[a.first] > cnt[b.first];
}

void dfs(int node) {
    cnt[node] = 1;
    for (auto to : list[node]) {
        lvl[to.first] = lvl[node] + 1;
        conf[to.first] = conf[node] ^ (1 << (to.second - 'a'));
        dfs(to.first);
        cnt[node] += cnt[to.first];
    }

    if (list[node].size())
        swap(list[node][0], list[node][ min_element(list[node].begin(), list[node].end(), cmp) - list[node].begin() ]);
}

void solve(int node, bool rm) {
    int i, to, bit;
    int aux = 0;

    if (cnt[node] == 1) {
        nodes[node] = new vector<int>;
        *nodes[node] = {node};

        if (!rm) down[conf[node]] = lvl[node];

        return;
    }

    for (i = 1; i < list[node].size(); i++) {
        to = list[node][i].first;
        solve(to, true);

        sol[node] = max(sol[node], sol[to]);
    }

    solve(list[node][0].first, false);
    nodes[node] = nodes[ list[node][0].first ];
    sol[node] = max(sol[node], sol[ list[node][0].first ]);


    aux = max(aux, lvl[node] + down[ conf[node] ]);
    for (bit = sigma; bit >= 1; bit >>= 1)
        aux = max(aux, lvl[node] + down[ conf[node] ^ bit ]);
    nodes[node]->pb(node);
    down[conf[node]] = max(down[conf[node]], lvl[node]);

    for (i = 1; i < list[node].size(); i++) {
        to = list[node][i].first;

        for (auto e : *nodes[to]) {
            nodes[node]->pb(e);

            aux = max(aux, lvl[e] + down[ conf[e] ]);
            for (bit = sigma; bit >= 1; bit >>= 1)
                aux = max(aux, lvl[e] + down[ conf[e] ^ bit ]);
        }

        for (auto e : *nodes[to])
            down[ conf[e] ] = max(down[ conf[e] ], lvl[e]);

        nodes[to]->clear();
        delete nodes[to];
    }

    sol[node] = max(sol[node], aux - 2 * lvl[node]);

    if (rm) {
        for (auto e : *nodes[node])
            down[ conf[e] ] = 0;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        scanf("%d %c", &x, &c);
        list[x].pb(mp(i, c));
        sigma = max(sigma, c - 'a');
    }

    sigma = 1 << sigma;

    lvl[1] = 10000000;
    dfs(1);

    solve(1, false);
    for (i = 1; i <= n; i++) printf("%d ", sol[i]);

    return 0;
}