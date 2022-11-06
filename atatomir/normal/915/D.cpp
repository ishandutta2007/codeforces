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

#define maxN 511

int n, m, i, x, y;
vector<int> list[maxN];
bool us[maxN];
vector<int> ord;
int id[maxN], cnt;

vector< pair<int, int> > edges;
vector< pair<int, int> > aux;
pair<int, int> deny;

void dfs(int node) {
    us[node] = true;
    for (auto to : list[node])
        if (!us[to] && mp(node, to) != deny)
            dfs(to);

    ord.pb(node);
}

void dfs2(int node, int dest) {
    if (node == dest) {
        edges = aux;
        return;
    }
    us[node] = true;

    for (auto to : list[node]) {
        if (us[to]) continue;
        aux.pb(mp(node, to));
        dfs2(to, dest);
        aux.pop_back();

        if (edges.size()) return;
    }
}

bool check(pair<int, int> _deny) {
    int i;

    deny = _deny;
    memset(us, 0, sizeof(us));

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        dfs(i);
    }

    reverse(ord.begin(), ord.end());
    for (i = 0; i < n; i++) id[ord[i]] = i;

    for (i = 1; i <= n; i++)
        for (auto to : list[i])
            if (id[i] > id[to] && mp(i, to) != deny)
                return false;

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
    }

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;
        dfs(i);
    }

    reverse(ord.begin(), ord.end());
    for (i = 0; i < n; i++) id[ord[i]] = i;

    for (i = 1; i <= n; i++)
        for (auto to : list[i])
            if (id[i] > id[to])
                cnt++, edges.pb(mp(i, to));

    if (cnt <= 1) {
        printf("Yes");
        return 0;
    }

    int n1 = edges[0].first;
    int n2 = edges[1].second;

    memset(us, 0, sizeof(us));
    edges.clear();

    aux.pb(mp(n1, n2));
    dfs2(n2, n1);

    for (auto e : edges) {
        if (check(e)) {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No");


    return 0;
}