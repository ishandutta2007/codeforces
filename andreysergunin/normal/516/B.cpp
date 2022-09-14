#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2100;
int d[MAXN][MAXN];
int r;

int a[MAXN * MAXN];
int n, m;

void f(int i, int j)
{

    if (i > 0 && d[i - 1][j] > 0)
        d[i - 1][j]--;
    if (i < n - 1 && d[i + 1][j] > 0)
        d[i + 1][j]--;
    if (j > 0 && d[i][j - 1] > 0)
        d[i][j - 1]--;
    if (j < m - 1 && d[i][j + 1] > 0)
        d[i][j + 1]--;


    if (i > 0 && d[i - 1][j] == 1)
        a[r++] = (i - 1) * m + j;
    if (i < n - 1 && d[i + 1][j] == 1)
        a[r++] = (i + 1) * m + j;
    if (j > 0 && d[i][j - 1] == 1)
        a[r++] = i * m + j - 1;
    if (j < m - 1 && d[i][j + 1] == 1)
        a[r++] = i * m + j + 1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    char s[MAXN][MAXN];
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = 0;
    int l = 0;
    r = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.')
            {
                if (i > 0 && s[i - 1][j] == '.')
                    d[i][j]++;
                if (i < n - 1 && s[i + 1][j] == '.')
                    d[i][j]++;
                if (j > 0 && s[i][j - 1] == '.')
                    d[i][j]++;
                if (j < m - 1 && s[i][j + 1] == '.')
                    d[i][j]++;
                if (d[i][j] == 1)
                    a[r++] = i * m + j;
            }
    while (l < r)
    {
        int i = a[l] / m;
        int j = a[l] % m;
        l++;
        //printf("%d %d\n", i, j);
        if (d[i][j] == 1)
        {
            if (d[i][j] == 1 && i > 0 && d[i - 1][j] > 0)
            {
                d[i - 1][j] = 0;
                s[i][j] = 'v';
                s[i - 1][j] = '^';
                d[i][j] = 0;
                f(i - 1, j);
            }
            if (d[i][j] == 1 && i < n - 1 && d[i + 1][j] > 0)
            {
                d[i + 1][j] = 0;
                s[i][j] = '^';
                s[i + 1][j] = 'v';
                d[i][j] = 0;
                f(i + 1, j);
            }
            if (d[i][j] == 1 && j > 0 && d[i][j - 1] > 0)
            {
                d[i][j - 1] = 0;
                s[i][j] = '>';
                s[i][j - 1] = '<';
                d[i][j] = 0;
                f(i, j - 1);
            }
            if (d[i][j] == 1 && j < m - 1 && d[i][j + 1] > 0)
            {
                d[i][j + 1] = 0;
                s[i][j] = '<';
                s[i][j + 1] = '>';
                d[i][j] = 0;
                f(i, j + 1);
            }
            f(i, j);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.')
            {
                printf("Not unique\n");
                return 0;
            }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%c", s[i][j]);
        printf("\n");
    }
    return 0;
}