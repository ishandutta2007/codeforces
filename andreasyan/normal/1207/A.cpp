#include <bits/stdc++.h>
using namespace std;

int b, p, f;
int h, c;

void solv()
{
    scanf("%d%d%d", &b, &p, &f);
    scanf("%d%d", &h, &c);
    int ans = 0;
    if (h > c)
    {
        while (b >= 2 && p >= 1)
        {
            ans += h;
            b -= 2;
            p--;
        }
        while (b >= 2 && f >= 1)
        {
            ans += c;
            b -= 2;
            f--;
        }
    }
    else
    {
        while (b >= 2 && f >= 1)
        {
            ans += c;
            b -= 2;
            f--;
        }
        while (b >= 2 && p >= 1)
        {
            ans += h;
            b -= 2;
            p--;
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