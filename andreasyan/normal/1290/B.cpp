#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char aa[N], a[N];

int p[N][26];

int main()
{
    scanf(" %s", aa);
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i - 1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
            p[i][j] = p[i - 1][j];
        p[i][a[i] - 'a']++;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l == r)
        {
            printf("Yes\n");
            continue;
        }
        if (a[l] != a[r])
        {
            printf("Yes\n");
            continue;
        }
        int q = 0;
        for (int j = 0; j < 26; ++j)
        {
            if (p[r][j] - p[l - 1][j] > 0)
                ++q;
        }
        if (q > 2)
        {
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }
    return 0;
}