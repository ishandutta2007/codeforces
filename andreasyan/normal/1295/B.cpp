#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, x;
char a[N];

void solv()
{
    scanf("%d%d", &n, &x);
    scanf(" %s", a);
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '0')
            ++s;
        else
            --s;
    }
    int ans = 0;
    int p = 0;
    for (int i = -1; i < n - 1; ++i)
    {
        if (i != -1)
        {
            if (a[i] == '0')
                ++p;
            else
                --p;
        }
        if (s == 0)
        {
            if (p == x)
            {
                printf("-1\n");
                return;
            }
            continue;
        }
        if ((x - p) % s == 0)
        {
            if (x == p)
                ++ans;
            else if ((s < 0) && (x - p) < 0)
                ++ans;
            else if ((s > 0) && (x - p) > 0)
                ++ans;
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