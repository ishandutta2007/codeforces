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

#define maxN 25

int n, m, i, j;
int mat[maxN][maxN];
int a[maxN][maxN];

void check(int c1, int c2) {
    int i, j;
    memcpy(a, mat, sizeof(a));
    int difs;

    for (i = 1; i <= n; i++)
        swap(a[i][c1], a[i][c2]);

    for (i = 1; i <= n; i++) {
        difs = 0;

        for (j = 1; j <= m; j++)
            if (a[i][j] != j) difs++;

        if (difs > 2) return;
    }

    printf("YES");
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &mat[i][j]);

    for (i = 1; i <= m; i++)
        for (j = i; j <= m; j++)
            check(i, j);

    printf("NO");

    return 0;
}