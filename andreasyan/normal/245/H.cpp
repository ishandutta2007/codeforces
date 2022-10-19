#include <bits/stdc++.h>
using namespace std;
const int N = 5003;

int n;
char aa[N], a[N];
bool c[N][N];
int s[N][N];
int ans[N][N];

int main()
{
    scanf("%s", &aa);
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i - 1];
    for (int d = 1; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            if (d == 1)
            {
                c[l][r] = true;
                continue;
            }
            if (d == 2)
            {
                if (a[l] == a[r])
                    c[l][r] = true;
                continue;
            }
            if (c[l + 1][r - 1] && a[l] == a[r])
            {
                c[l][r] = true;
            }
        }
    }
    for (int r = 1; r <= n; ++r)
    {
        for (int l = r; l >= 1; --l)
        {
            s[r][l] = s[r][l + 1] + c[l][r];
        }
    }
    for (int l = 1; l <= n; ++l)
    {
        for (int r = l; r <= n; ++r)
        {
            ans[l][r] = ans[l][r - 1] + s[r][l];
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", ans[l][r]);
    }
    return 0;
}