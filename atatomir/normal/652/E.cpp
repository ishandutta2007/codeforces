#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011

int n, m, i, x, y, c, S, D;
vector< pair<int, int> > list[maxN];
vector<int> list_to[maxN], list_from[maxN];

int lvl[maxN];
int cnt;
vector<int> act, way;
bool us[maxN];

int comps;
int comp[maxN];
bool special[maxN];
stack<int> St;


void dfs(int node) {
    us[node] = true;

    if (node == D) {
        if (way.empty()) way = act;
        if (cnt) {
            printf("YES");
            exit(0);
        }
    }

    for (auto to : list[node]) {
        if (us[to.first]) {
            if (lvl[to.first] + 1 < lvl[node]) {
                list_to[node].pb(to.first);
                list_from[to.first].pb(node);
            }
            continue;
        }

        lvl[to.first] = lvl[node] + 1;
        list_to[node].pb(to.first);
        list_from[to.first].pb(node);

        act.pb(to.first);
        cnt += to.second;
        dfs(to.first);
        cnt -= to.second;
        act.pop_back();
    }

    St.push(node);
}

void dfs_from(int node) {
    us[node] = true;
    comp[node] = comps;

    for (int to : list_from[node]) {
        if (us[to]) continue;
        dfs_from(to);
    }
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &c);
        list[x].pb(mp(y, c));
        list[y].pb(mp(x, c));
    }
    scanf("%d%d", &S, &D);

    act.pb(S);
    dfs(S);

    memset(us, 0, sizeof(us));
    while (!St.empty()) {
        int node = St.top(); St.pop();
        if (!us[node])
            comps++, dfs_from(node);
    }

    for (int node = 1; node <= n; node++)
        for (auto to : list[node])
            if (to.second)
                if (comp[node] == comp[to.first])
                    special[comp[node]] = true;

    bool yes = false;
    for (auto e : way)
        if (special[comp[e]])
            yes = true;

    printf((yes ? "YES" : "NO"));

    return 0;
}