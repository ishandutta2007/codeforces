#include <bits/stdc++.h>
using namespace std;

int n, d;

void solv()
{
    scanf("%d%d", &n, &d);
    int ans = d;
    for (int i = 1; i <= 100000; ++i)
    {
        int yans = i + (d / (i + 1));
        if ((d % (i + 1)))
            ++yans;
        ans = min(ans, yans);
    }
    if (ans <= n)
        printf("YES\n");
    else
        printf("NO\n");
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