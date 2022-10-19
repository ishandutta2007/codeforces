#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[N];
bool c[N];

int ans;
void gor()
{
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        maxu = max(maxu, a[i]);
    }
    ans += maxu;
    for (int i = 1; i <= n; ++i)
    {
        if (maxu % a[i] == 0)
            c[i] = true;
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        c[i] = false;
        scanf("%d", &a[i]);
    }
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
        maxu = max(maxu, a[i]);

    int ans1 = 0;
    if (maxu % 2 == 0 && maxu % 3 == 0 && maxu % 5 == 0)
    {
        bool z2 = false, z3 = false, z5 = false;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == maxu / 2)
                z2 = true;
            if (a[i] == maxu / 3)
                z3 = true;
            if (a[i] == maxu / 5)
                z5 = true;
        }
        if (z2 && z3 && z5 && (maxu / 2) % (maxu / 3) && (maxu / 2) % (maxu / 5) && (maxu / 3) % (maxu / 5))
            ans1 = maxu / 2 + maxu / 3 + maxu / 5;
    }
    ans = 0;
    gor();
    gor();
    gor();
    printf("%d\n", max(ans, ans1));
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}