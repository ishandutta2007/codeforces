#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;
int a[200][200];
int h[200];
int d[200];
int h1[200];
int d1[200];
int l[10];
int g[10];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, i, j, res = 0, k;
    bool check;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    cin >> l[0] >> l[1] >> l[2];
    sort(l, l + 3);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            h[i] += a[i][j];
            d[j] += a[i][j];
        }
    for (i = 0; i < n; i++)
    {
         if (i)
            h1[i] += h1[i - 1];
        h1[i] += h[i];
    }
    for (j = 0; j < m; j++)
    {
         if (j)
            d1[j] += d1[j - 1];
        d1[j] += d[j];
    }
    ////

    /////
///////////////////////////////////////// sdasd/////////////
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < i; j++)
        {
            g[0] = h1[j];
            g[1] = h1[i] - h1[j];
            g[2] = h1[n - 1] - h1[i];
            sort(g, g + 3);
            check = true;
            for (k = 0; k < 3; k++)
                if (g[k] != l[k])
                    check = false;
            if (check)
                res++;
        }
    for (i = 0; i < m - 1; i++)
        for (j = 0; j < i; j++)
        {
            g[0] = d1[j];
            g[1] = d1[i] - d1[j];
            g[2] = d1[m - 1] - d1[i];
            sort(g, g + 3);
            check = true;
            for (k = 0; k < 3; k++)
                if (g[k] != l[k])
                    check = false;
            if (check)
                res++;
        }
    cout << res;
    return 0;
}