#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

void solv()
{
    scanf("%d%d", &n, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int ans = 0;
    int q = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] != a[i - 1] - 1)
        {
            if (q % 2 == 1)
                ++ans;
            q = 1;
        }
        else
            ++q;
    }
    if (q % 2 == 1 && a[n] > 1)
        ++ans;
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