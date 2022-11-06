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

#define maxN 2511

int n, i, j, x, y;
int a[maxN][maxN], b[maxN][maxN];
vector< pair<int, int> > aux;

int dad[maxN];
vector<int> comp[maxN];

void not_magic() {
    printf("NOT MAGIC");
    exit(0);
}

void magic() {
    printf("MAGIC");
    exit(0);
}

int Find(int x) {
    if (dad[x] == x) return x;
    dad[x] = Find(dad[x]);
    return dad[x];
}

bool Merge(int x, int y, int v) {
    x = Find(x);
    y = Find(y);

    if (x == y) return false;

    for (auto e1 : comp[x])
        for (auto e2 : comp[y])
            b[e1][e2] = b[e2][e1] = v;

    for (auto e : comp[y])
        comp[x].pb(e);

    comp[y].clear();
    dad[y] = dad[x];

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (i = 1; i <= n; i++)
        if (a[i][i] != 0)
            not_magic();

    for (i = 1; i <= n; i++) {
        for (j = 1; j < i; j++) {
            aux.pb(mp(a[i][j], i * 3000 + j));
            if (a[i][j] != a[j][i])
                not_magic();
        }
    }

    for (i = 1; i <= n; i++) dad[i] = i, comp[i] = {i};
    sort(aux.begin(), aux.end());

    for (auto e : aux) {
        x = e.second / 3000;
        y = e.second % 3000;

        Merge(x, y, e.first);
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j < i; j++)
            if (a[i][j] != b[i][j])
                not_magic();

    magic();
    return 0;
}