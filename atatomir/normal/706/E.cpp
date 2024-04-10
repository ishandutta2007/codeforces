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

#define maxN 1024

int n, m, q, i, j;
int xx1, xx2, yy1, yy2, l, c;
int mat[maxN * maxN];
int R[maxN * maxN], D[maxN * maxN];


int get_cell(int x, int y) {
    int act = 0;

    for (int i = 1; i <= x; i++)
        act = D[act];
    for (int i = 1; i <= y; i++)
        act = R[act];

    return act;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &mat[i * (m + 1) + j]);

    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++)
            R[i * (m + 1) + j] = i * (m + 1) + j + 1,
            D[i * (m + 1) + j] = (i + 1) * (m + 1) + j;

    for (int qq = 1; qq <= q; qq++) {
        scanf("%d%d%d%d%d%d", &xx1, &yy1, &xx2, &yy2, &l, &c);

        int cell1 = get_cell(xx1 - 1, yy1 - 1);
        int cell2 = get_cell(xx2 - 1, yy2 - 1);
        int p1, p2;

        pair<int, int> r1 = mp(get_cell(xx1, yy1 + c - 1), get_cell(xx2, yy2 + c - 1));
        pair<int, int> r2 = mp(get_cell(xx1 + l - 1, yy1), get_cell(xx2 + l - 1, yy2));

        //! top
        for (p1 = R[cell1], p2 = R[cell2], i = 1; i <= c; p1 = R[p1], p2 = R[p2], i++)
            swap(D[p1], D[p2]);

        //! left
        for (p1 = D[cell1], p2 = D[cell2], i = 1; i <= l; p1 = D[p1], p2 = D[p2], i++)
            swap(R[p1], R[p2]);

        cell1 = r1.first;
        cell2 = r1.second;

        //! right
        for (p1 = cell1, p2 = cell2, i = 1; i <= l; p1 = D[p1], p2 = D[p2], i++)
            swap(R[p1], R[p2]);

        cell1 = r2.first;
        cell2 = r2.second;

        //! bottom
        for (p1 = cell1, p2 = cell2, i = 1; i <= c; p1 = R[p1], p2 = R[p2], i++)
            swap(D[p1], D[p2]);
    }

    int act = R[0];
    for (i = 1; i <= n; i++) {
        act = D[act];

        for (int aux = act, j = 1; j <= m; aux = R[aux], j++)
            printf("%d ", mat[aux]);

        printf("\n");
    }


    return 0;
}