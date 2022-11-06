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

int n, i, x, y, ans;
vector<int> list[maxN];
int col[maxN];

vector<int> aux;

void dfs(int node, int root) {
    int v, pos;

    aux = {col[node]};

    for (auto to : list[node]) {
        if (col[to] == 0) continue;
        aux.pb(col[to]);
    }

    sort(aux.begin(), aux.end());
    pos = 0; v = 1;

    for (auto to : list[node]) {
        if (to == root) continue;
        if (col[to] != 0) continue;

        while (pos < aux.size()) {
            if (aux[pos] == v) {
                pos++;
                v++;
            } else {
                break;
            }
        }

        col[to] = v;
        v++;
    }

    for (auto to : list[node])
        if (to != root)
            dfs(to, node);
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

    if (n == 1) {
        printf("1\n1\n");
        return 0;
    }

    if (n == 2) {
        printf("2\n1 2\n");
        return 0;
    }

    for (i = 1; i <= n; i++)
        ans = max(ans, 1 + (int)list[i].size());

    col[1] = 1;
    dfs(1, 0);

    printf("%d\n", ans);
    for (i = 1; i <= n; i++)
        printf("%d ", col[i]);


    return 0;
}