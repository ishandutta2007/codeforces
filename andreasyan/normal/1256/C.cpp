#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m, d;
int a[N];
int s[N];

int ans[N];
int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    for (int i = m; i >= 1; --i)
        s[i] = s[i + 1] + a[i];
    int x = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (x + d + s[i] > n)
        {
            for (; i <= m; ++i)
            {
                for (int j = 0; j < a[i]; ++j)
                    ans[++x] = i;
            }
            break;
        }
        x += d;
        --x;
        for (int j = 0; j < a[i]; ++j)
            ans[++x] = i;
    }
    if (x + d <= n)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}