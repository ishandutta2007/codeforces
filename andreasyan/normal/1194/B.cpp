#include <bits/stdc++.h>
using namespace std;
const int N = 50004;

int n, m;
int ii[N], jj[N];
char** a;

void solv()
{
    scanf("%d%d", &n, &m);
    a = new char*[n + 1];
    for (int i = 0; i < n; ++i)
        a[i] = new char[m + 1];
    for (int i = 0; i < n; ++i)
    {
        scanf(" %s", a[i]);
    }
    for (int i = 0; i < n; ++i)
        ii[i] = 0;
    for (int j = 0; j < m; ++j)
        jj[j] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == '*')
            {
                ii[i]++;
                jj[j]++;
            }
        }
    }
    int ans = n * m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int yans = n - ii[i] + m - jj[j];
            if (a[i][j] == '.')
                --yans;
            ans = min(ans, yans);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}