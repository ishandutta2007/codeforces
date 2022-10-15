#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 202;

int n, m, l;
long long k;
int a[MAXN];
int d[MAXN];
char s[MAXN];
long long f[MAXN][MAXN];


bool opr_sort(const int &i, const int &j)
{
    return a[i] < a[j];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    cin >> n >> m >> k;

    l = n + m - 1;
    for (int i = 0; i < l; i++)
    {
        a[i] = n * m;
        d[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);
            if (x < a[i + j]) a[i + j] = x;
        }
    }

    sort(d, d + l, opr_sort);

    for (int I = 0; I < l; I++)
    {
        s[d[I]] = '(';

        f[0][0] = 1;
        for (int i = 0; i < l; i++)
            for (int j = i & 1; j <= i && j <= l - i; j += 2)
                if (f[i][j])
                {
                    if (f[i][j] > k) f[i][j] = k;

                    if (s[i] != ')') f[i + 1][j + 1] += f[i][j];
                    if (s[i] != '(' && j) f[i + 1][j - 1] += f[i][j];
                    f[i][j] = 0;
                }
//        printf("%d %lld\n", d[I], f[l][0]);
        if (k > f[l][0])
        {
            k -= f[l][0];
            s[d[I]] = ')';
        }
        f[l][0] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%c", s[i + j]);
        printf("\n");
    }
    return 0;
}