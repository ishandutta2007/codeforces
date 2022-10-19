#include <bits/stdc++.h>
using namespace std;
const int N = 602;

int n, m;
int a[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    }
    int mm = 0;
    for (int j = 0; j < m; ++j)
    {
        if (abs(a[n / 2][j] - a[n / 2 - 1][j]) <= 20)
            ++mm;
    }
    if (mm >= (m / 2))
        printf("NO\n");
    else
        printf("YES\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}