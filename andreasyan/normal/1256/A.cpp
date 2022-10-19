#include <bits/stdc++.h>
using namespace std;

int a, b, n, s;

void solv()
{
    scanf("%d%d%d%d", &a, &b, &n, &s);
    if (s / n <= a)
        s -= (s / n) * n;
    else
        s -= a * n;
    if (s <= b)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
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