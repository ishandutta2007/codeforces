#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, p, k;
int a[N];

void solv()
{
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = 0;
    int pp = 0;
    for (int i = 0; i < k; ++i)
    {
        pp += a[i];
        int yans = i;
        int yp = pp;
        for (int j = i + k; j <= n; j += k)
        {
            if (yp + a[j] <= p)
            {
                yp += a[j];
                yans = j;
            }
        }
        if (yp <= p)
            ans = max(ans, yans);
    }
    printf("%d\n", ans);
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