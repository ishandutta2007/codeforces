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

int n, i;
pair<int, int> v[maxN];
int pa[maxN];
bool us[maxN];
int col[maxN];

void dfs(int node) {
    if (us[node]) return;

    int oth = (node & 1 ? node + 1 : node - 1);
    us[node] = us[oth] = true;
    col[node] = 0;
    col[oth] = 1;

    dfs(pa[oth]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &v[i].first, &v[i].second);
        pa[v[i].first] = v[i].second;
        pa[v[i].second] = v[i].first;
    }

    for (i = 1; i <= 2 * n; i++)
        dfs(i);

    for (i = 1; i <= n; i++)
        printf("%d %d\n", col[ v[i].first ] + 1, col[ v[i].second ] + 1);


    return 0;
}