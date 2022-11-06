#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 2016

int a, b, m, i, j, x, y, maxi;
int list[maxN][maxN];
map< pair<int, int>, int > M;
int ans[100011];

int get_free(int node) {
    int i;
    for (i = 1; list[node][i] != 0; i++);
    return i;
}

void colour(int x, int y, int c1, int c2) {
    maxi = max(maxi, c1);

    if (list[y][c1] == 0) {
        // happiness
        list[x][c1] = y;
        list[y][c1] = x;
        return;
    }

    int z = list[y][c1];
    list[x][c1] = y;
    list[y][c1] = x;

    list[z][c1] = 0;

    colour(y, z, c2, c1);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &a, &b, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        M[mp(x, y + a)] = i;

        colour(x, y + a, get_free(x), get_free(y + a));
    }

    for (i = 1; i <= a; i++) {
        for (j = 1; j <= a + b; j++) {
            if (list[i][j] == 0) continue;

            ans[ M[mp(i, list[i][j])] ] = j;
        }
    }

    printf("%d\n", maxi);
    for (i = 1; i <= m; i++)
        printf("%d ", ans[i]);


    return 0;
}